#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

const int KSIZE = 3;

// Edge detection functions
int detectBySobel(Mat, Mat);
int detectByPrewitt(Mat, Mat);
int detectByLaplace(Mat, Mat);


// main function
int main(int argc, char** argv)
{
	Mat image;
	image = imread(argv[1], IMREAD_GRAYSCALE);
	if (!image.data)
	{
		cout << "Error: Khong the mo anh !" << std::endl;
		return -1;
	}

	if (argc == 3)
	{
		if (strcmp(argv[2], "-sobel") == 0)
		{
			Mat dst(image.rows, image.cols, CV_8UC1);
			detectBySobel(image, dst);
		}
		else if (strcmp(argv[2], "-prewitt") == 0)
		{
			Mat dst(image.rows, image.cols, CV_8UC1);
			detectByPrewitt(image, dst);
		}
		if (strcmp(argv[2], "-laplace") == 0)
		{
			Mat dst(image.rows, image.cols, CV_8UC1);
			detectByLaplace(image, dst);
		}
		if (strcmp(argv[2], "-canny") == 0)
			cout << "Xin loi ! Tinh nang chua hoan thanh !";
	}
	else
	{
		cout << "Error: Loi cau lenh !" << endl;
		return -1;
	}
	return 0;
}

Mat my2dFilter(Mat& img, float kernel[KSIZE][KSIZE])
{
	// get image size
	int nRow = img.rows;
	int nCol = img.cols;

	// find center position of kernel (half of kernel size)
	int kCenter = KSIZE / 2;

	// result image
	Mat resImg(nRow, nCol, img.type());

	// get size of convolution stride
	int strideSize = img.step[0];

	// init offset matrix
	vector<int> offset;
	for (int i = -kCenter; i <= kCenter; i++)
		for (int j = -kCenter; j <= kCenter; j++)
			offset.push_back(strideSize * i + j);


	// get img value address
	uchar* resP = resImg.data;
	uchar* imgP = img.data;

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++, imgP++, resP++)
		{
			// out of convolution calculate zone
			if (i < kCenter || i >= nRow - kCenter || j < kCenter || j >= nCol - kCenter)
			{
				resP[0] = 0;
				continue;
			}

			float accum = 0;
			for (int x = -kCenter; x <= kCenter; x++)
				for (int y = -kCenter; y <= kCenter; y++)
					accum += imgP[offset[(x + kCenter)*KSIZE + y + kCenter]] * kernel[x + kCenter][y + kCenter];
			
			resP[0] = (accum < 0) ? 0:(int)accum;
		}

	}
	return resImg;
}

int detectBySobel(Mat src, Mat dst)
{
	// sobel kernel x and y
	float xKernel[KSIZE][KSIZE] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
	float yKernel[KSIZE][KSIZE] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };

	// Sobel apply filter gradient x, y
	Mat dst_x = my2dFilter(src, xKernel);
	Mat dst_y = my2dFilter(src, yKernel);

	// get image address
	uchar* dstP = dst.data;
	uchar* xP = dst_x.data;
	uchar* yP = dst_y.data;

	// Sobel edge detection: G = sqrt( Gx^2 + Gy^2)
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++, dstP++, xP++, yP++)
			dstP[0] = (uchar)(sqrt(xP[0]*xP[0] + yP[0]*yP[0]));

	imshow("Sobel gradient x", dst_x);
	imshow("Sobel gradient y", dst_y);
	imshow("Sobel result", dst);
	waitKey(0);
	return 1;
}

int detectByPrewitt(Mat src, Mat dst)
{
	// Prewitt kernel x and y
	float kernel_x[][KSIZE] = { {1, 0, -1}, {1, 0, -1}, {1, 0, -1} };
	float kernel_y[][KSIZE] = { {-1,-1,-1},{0,0,0},{1,1,1} };

	// Prewitt apply filter gradient x, y
	Mat image_x = my2dFilter(src, kernel_x);
	Mat image_y = my2dFilter(src, kernel_y);

	// get image address
	uchar* dstP = dst.data;
	uchar* xP = image_x.data;
	uchar* yP = image_y.data;

	// Sobel edge detection: G = sqrt( Gx^2 + Gy^2)
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++, dstP++, xP++, yP++)
			dstP[0] = (uchar)(sqrt(xP[0] * xP[0] + yP[0] * yP[0]));

	imshow("Prewitt gradient x", image_x);
	imshow("Prewitt gradient y", image_y);
	imshow("Prewitt result", dst);
	waitKey(0);
	return 1;
}
int detectByLaplace(Mat src, Mat dst)
{
	// Laplace kernel
	float kernel[][KSIZE] = { {1,1,1},{1,-8,1},{1,1,1} };
	
	// Laplace apply filter
	dst = my2dFilter(src, kernel);

	imshow("Laplace result", dst);
	waitKey(0);
	return 1;
}