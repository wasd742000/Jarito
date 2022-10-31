#include "Blur.h"

int Blur::BlurImage(const Mat& sourceImage, Mat& destinationImage, int kWidth, int kHeight, int method)
{
	// Khong phai ảnh grayscale
	if (sourceImage.channels() != 1) return 1;

	int nRow = sourceImage.rows;
	int nCol = sourceImage.cols;
	int step = sourceImage.step[0];

	switch (method)
	{

	// pp Average blur
	case 0: 
	{
		Convolution conv;
		vector<float> kernel;

		float n = kWidth * kHeight;
		for (int i = 0; i < kWidth * kHeight; i++) 
			kernel.push_back(1.0/ n);

		conv.SetKernel(kernel, kWidth, kHeight);

		destinationImage = Mat(nRow - kHeight + 1, nCol - kWidth + 1, CV_32FC1, Scalar(0));

		conv.DoConvolution(sourceImage, destinationImage);

		for (int i = 0; i < destinationImage.rows; i++) 
		{
			float* tmpRow = destinationImage.ptr<float>(i);
			for (int j = 0; j < destinationImage.cols; j++) 
				tmpRow[j] /= 255.0;
		}
	}
		  break;

	// pp Median blur
	case 1: 
	{
		destinationImage = Mat(nRow - kHeight + 1, nCol - kWidth + 1, CV_32FC1, Scalar(0));

		int kHalfWidth = kWidth >> 1;
		int kHalfHeight = kHeight >> 1;

		vector<int> offsets;
		for (int y = -kHalfHeight; y <= kHalfHeight; y++)
			for (int x = -kHalfWidth; x <= kHalfWidth; x++)
				offsets.push_back(y * step + x);

		uchar* p = (uchar*)sourceImage.data;

		for (int i = 0; i < destinationImage.rows; i++) 
		{
			float* tmpRow = destinationImage.ptr<float>(i);
			for (int j = 0; j < destinationImage.cols; j++) 
			{
				int i_source = i + (kWidth / 2), j_source = j + (kHeight / 2);
				uchar* pSource = p + i_source * step + j_source;
				vector<uchar> value;
				// Tim lan can
				for (int k = 0; k < offsets.size(); k++) {
					value.push_back(pSource[offsets[k]]);
				}
				//Sap xep de tim trung vi
				sort(value.begin(), value.begin() + value.size());
				tmpRow[j] = value[value.size() / 2 + 1] / 255.0;
			}
		}
	}
		  break;

	// pp Gaussian blur
	case 2: 
	{
		Mat tmp = sourceImage.clone();
		destinationImage = Mat(nRow, nCol, CV_32FC1, Scalar(0.0));
		vector <int> dx;
		vector <int> dy;

		for (int i = 0; i < kHeight; i++)
			for (int j = 0; j < kWidth; j++) 
			{
				dx.push_back(i - (kHeight / 2));
				dy.push_back(j - (kWidth / 2));
			}
		float stddev;
		if ((kHeight == 3) && (kWidth == 3)) stddev = 3;
		else
			stddev = (1.0 * kHeight / 3) * (1.0 * kWidth / 3) * 3;
		vector <float> h(kHeight * kWidth);
		for (int k = 0; k < kHeight * kWidth; k++) { //calculate h(i,j) in gaussian distribution
			int i = dx[k], j = dy[k];
			float disValue = 1 / (sqrt(2 * cusPI) * stddev) * exp(-(i * i + j * j) / (2 * stddev * stddev));
			h[k] = disValue;
		}
		for (int i = 0; i < nRow; i++)
			for (int j = 0; j < nCol; j++) 
			{
				float sumDisValue = 0;
				for (int k = 0; k < kHeight * kWidth; k++) 
				{
					int i_pos = i - dx[k];
					int j_pos = j - dy[k];
					float dataImage;
					if ((i_pos - (kHeight / 2) < 0) || (i_pos + (kHeight / 2) >= nRow)
						|| (j_pos - (kWidth / 2) < 0) || (j_pos + (kWidth / 2) >= nCol)) {
						dataImage = 1.0 * tmp.ptr<uchar>(i)[j];
					}
					else
						dataImage = 1.0 * tmp.ptr<uchar>(i_pos)[j_pos];
					sumDisValue += dataImage * h[k];
				}
				if (sumDisValue > 255.0)
					destinationImage.ptr<float>(i)[j] = 255;
				else
					destinationImage.ptr<float>(i)[j] = sumDisValue;
			}

		//MinMax Scaler
		float minValue = 255;
		for (int i = 0; i < nRow; i++)
			for (int j = 0; j < nCol; j++)
				if (destinationImage.ptr<float>(i)[j] < minValue) minValue = destinationImage.ptr<float>(i)[j];

		for (int i = 0; i < nRow; i++)
			for (int j = 0; j < nCol; j++)
				destinationImage.ptr<float>(i)[j] = (destinationImage.ptr<float>(i)[j] - minValue) / (255 - minValue);
	}
		  break;

	}

	return 0;
}

Blur::Blur()
{
}

Blur::~Blur()
{
}
