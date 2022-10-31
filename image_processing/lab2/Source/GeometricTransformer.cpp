#include "GeometricTransformer.h"


PixelInterpolate::PixelInterpolate()
{
}

PixelInterpolate::~PixelInterpolate()
{
}


uchar BilinearInterpolate::Interpolate(float tx, float ty, uchar* pSrc, int srcWidthStep, int nChannels)
{

	int l = floor(tx);
	int k = floor(ty);
	float a = tx - l;
	float b = ty - k;

	float res = (1 - a) * (1 - b) * pSrc[srcWidthStep * k + nChannels * l] +
		a * (1 - b) * pSrc[srcWidthStep * k + nChannels * (l + 1)] +
		b * (1 - a) * pSrc[srcWidthStep * (k + 1) + nChannels * l] +
		a * b * pSrc[srcWidthStep * (k + 1) + nChannels * (l + 1)];
	return uchar(round(res));
}

BilinearInterpolate::BilinearInterpolate()
{
}

BilinearInterpolate::~BilinearInterpolate()
{
}


uchar NearestNeighborInterpolate::Interpolate(float tx, float ty, uchar* pSrc, int srcWidthStep, int nChannels)
{

	
	int x = int(round(tx));
	int y = int(round(ty));
	
	int i = x * nChannels + y * srcWidthStep;
	return pSrc[i];
}

NearestNeighborInterpolate::NearestNeighborInterpolate()
{
}

NearestNeighborInterpolate::~NearestNeighborInterpolate()
{
}

void AffineTransform::Translate(float dx, float dy) {
	Mat af_matrix = Mat::eye(3, 3, CV_32FC1);
	af_matrix.at<float>(0, 2) = dx;
	af_matrix.at<float>(1, 2) = dy;
	this->_matrixTransform = af_matrix * this->_matrixTransform;
}

void AffineTransform::Rotate(float angle) {
	Mat af_matrix = Mat::eye(3, 3, CV_32FC1);
	af_matrix.at<float>(0, 0) = cos(angle * M_PI / 180);
	af_matrix.at<float>(0, 1) = -sin(angle * M_PI / 180);
	af_matrix.at<float>(1, 0) = sin(angle * M_PI / 180);
	af_matrix.at<float>(1, 1) = cos(angle * M_PI / 180);

	this->_matrixTransform = af_matrix * this->_matrixTransform;
}

void AffineTransform::Scale(float sx, float sy)
{
	Mat matrix = Mat::zeros(3, 3, CV_32FC1);
	matrix.at<float>(0, 0) = sx;
	matrix.at<float>(1, 1) = sy;
	matrix.at<float>(2, 2) = 1;

	this->_matrixTransform = matrix * this->_matrixTransform;
}

void AffineTransform::TransformPoint(float& x, float& y)
{
	float res_x = 0, res_y = 0;
	res_x = _matrixTransform.at<float>(0, 0) * x + _matrixTransform.at<float>(0, 1) * y + _matrixTransform.at<float>(0, 2);
	res_y = _matrixTransform.at<float>(1, 0) * x + _matrixTransform.at<float>(1, 1) * y + _matrixTransform.at<float>(1, 2);

	x = res_x;
	y = res_y;
}

AffineTransform::AffineTransform()
{
	this->_matrixTransform = Mat::eye(3, 3, CV_32FC1);
}

AffineTransform::~AffineTransform()
{
}

int GeometricTransformer::Transform(const Mat& beforeImage, Mat& afterImage, AffineTransform* transformer, PixelInterpolate* interpolator)
{
	if (beforeImage.data == NULL || beforeImage.channels() != afterImage.channels())
	{
		return 0;
	}

	int srcRow = beforeImage.rows;
	int srcCol = beforeImage.cols;
	int srcWidthStep = beforeImage.step1();

	int dstRow = afterImage.rows;
	int dstCol = afterImage.cols;
	int dstWidthStep = afterImage.step1();

	
	int nChannel = beforeImage.channels();

	uchar* pSrcData = (uchar*)beforeImage.data;
	uchar* pDstData = (uchar*)afterImage.data;

	for (int y = 0; y < dstRow; y++)
	{
		for (int x = 0; x < dstCol; x++)
		{
			float tx = x, ty = y;
			transformer->TransformPoint(tx, ty);

			for (int k = 0; k < nChannel; k++)
			{
				uchar color = 0;
				if (tx >= 0 && tx <= srcCol && ty >= 0 && ty <= srcRow)
				{
					color = interpolator->Interpolate(tx, ty, pSrcData + k, srcWidthStep, nChannel);
				}

				int index = y * dstWidthStep + x * nChannel + k;
				pDstData[index] = color;
			}
		}
	}
	return 1;
}

int GeometricTransformer::RotateKeepImage(const Mat& srcImage, Mat& dstImage, float angle, PixelInterpolate* interpolator)
{
	if (srcImage.data == NULL)
	{
		return 0;
	}

	int srcRow = srcImage.rows;
	int srcCol = srcImage.cols;
	int nChannel = srcImage.channels();

	float w = float(srcCol);
	float h = float(srcRow);
	float dg = sqrt(w * w + h * h);

	float alpha0 = atan2(h, w);
	float new_w = max(fabs(dg * cos(-alpha0 + angle)),
		fabs(dg * cos(alpha0 + angle)));
	float new_h = max(fabs(dg * sin(-alpha0 + angle)),
		fabs(dg * sin(alpha0 + angle)));

	int dstRow = int(ceil(new_h));
	int dstCol = int(ceil(new_w));

	
	if (nChannel == 1)
		dstImage = Mat(dstRow, dstCol, CV_8UC1, Scalar(0));
	else if (nChannel == 3)
		dstImage = Mat(dstRow, dstCol, CV_8UC3, Scalar(0));

	// Biến đổi affine ngược
	AffineTransform* affineTrans = new AffineTransform();
	affineTrans->Translate(-new_w / 2, -new_h / 2);
	affineTrans->Rotate(-angle);
	affineTrans->Translate(srcCol / 2.0f, srcRow / 2.0f);


	int res = this->Transform(srcImage, dstImage, affineTrans, interpolator);
	return res;
}

int GeometricTransformer::RotateUnkeepImage(const Mat& srcImage, Mat& dstImage, float angle, PixelInterpolate* interpolator)
{
	if (srcImage.data == NULL)
	{
		return 0;
	}

	int srcRow = srcImage.rows;
	int srcCol = srcImage.cols;
	int nChannel = srcImage.channels();

	int dstRow = srcRow;
	int dstCol = srcCol;

	if (nChannel == 1)
		dstImage = Mat(dstRow, dstCol, CV_8UC1, Scalar(0));
	else if (nChannel == 3)
		dstImage = Mat(dstRow, dstCol, CV_8UC3, Scalar(0));

	// Biến đổi affine ngược
	AffineTransform* affineTrans = new AffineTransform();
	affineTrans->Translate(-srcCol / 2.0f, -srcRow / 2.0f);
	affineTrans->Rotate(-angle);
	affineTrans->Translate(srcCol / 2.0f, srcRow / 2.0f);

	int res = this->Transform(srcImage, dstImage, affineTrans, interpolator);
	return res;
}

int GeometricTransformer::Scale(const Mat& srcImage, Mat& dstImage, float sx, float sy, PixelInterpolate* interpolator)
{
	if (srcImage.data == NULL || sx < 0.001 || sy < 0.001)
	{
		return 0;
	}

	int srcRow = srcImage.rows;
	int srcCol = srcImage.cols;
	int nChannel = srcImage.channels();

	int dstRow = int(ceil(srcRow * sy));
	int dstCol = int(ceil(srcCol * sx));

	dstImage = Mat(dstRow, dstCol, CV_8UC3, Scalar(0));

	// Biến đổi affine ngược
	AffineTransform* affineTrans = new AffineTransform();
	affineTrans->Scale(1 / sx, 1 / sy);

	int res = this->Transform(srcImage, dstImage, affineTrans, interpolator);
	return res;
}

int GeometricTransformer::Resize(const Mat& srcImage, Mat& dstImage, int newWidth, int newHeight, PixelInterpolate* interpolator)
{
	if (srcImage.data == NULL || newWidth <= 0 || newHeight <= 0)
	{
		return 0;
	}

	int srcRow = srcImage.rows;
	int srcCol = srcImage.cols;
	int nChannel = srcImage.channels();

	// Tỉ lệ scale
	float sx = float(newWidth) / srcCol;
	float sy = float(newHeight) / srcRow;

	int res = this->Scale(srcImage, dstImage, sx, sy, interpolator);
	return res;
}

int GeometricTransformer::Flip(const Mat& srcImage, Mat& dstImage, bool direction, PixelInterpolate* interpolator)
{
	int sR = srcImage.rows;
	int sC = srcImage.cols;
	int channels = srcImage.channels();
	int wStep = sC * channels;

	// Ảnh mới cùng kích thước ảnh gốc
	dstImage.release();
	dstImage = srcImage.clone();
	const size_t eSize = srcImage.elemSize();

	if (direction == 1)
	{
		// Đối xứng ngang: hoán đổi giá trị điểm ảnh giữa các dòng
		for (int i = 0; i < sR; i++)
		{
			char* pLine = dstImage.ptr<char>(i);
			for (int j = 0; j < sC / 2; j++)
			{
				char* tmp,
					* p = pLine + (sC - j) * channels;
				tmp = new char[eSize];

				memcpy(tmp, p, eSize);
				memcpy(p, pLine + j * channels, eSize);
				memcpy(pLine + j * channels, tmp, eSize);
				delete[]tmp;
			}
		}
	}
	else
	{
		// Đối xứng đứng: đối xứng giá trị các điểm ảnh trên mỗi dòng
		
		for (int i = 0; i < sR / 2; i++)
		{

			char* pLine = dstImage.ptr<char>(i);
			char* temp,
				* p = dstImage.ptr<char>(sR - i - 1);

			temp = new char[eSize * sC];
			memcpy(temp, p, eSize * sC);
			memcpy(p, pLine, eSize * sC);
			memcpy(pLine, temp, eSize * sC);
			delete[]temp;
		}
	}
	return 0;
};

GeometricTransformer::GeometricTransformer()
{
}

GeometricTransformer::~GeometricTransformer()
{
}

