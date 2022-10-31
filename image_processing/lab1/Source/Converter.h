#pragma once
#include <math.h> 
#include "opencv2/opencv.hpp"

using namespace cv;

class Converter
{
	
	int RGB2GrayScale(const Mat& srcImg, Mat& dstImg)
	{
		if (srcImg.data == NULL)
			return 0;

		int width = srcImg.cols, height = srcImg.rows;
	

		dstImg = Mat(height, width, CV_8UC1);

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				Vec3b tmp = srcImg.at<Vec3b>(x, y);
				dstImg.at<uchar>(x, y) = round((tmp[0] + tmp[1] + tmp[2]) / 3);
			}
		}
		return 1;
	}


	int RGB2HSV(const Mat& srcImg, Mat& dstImg)
	{
		if (srcImg.data == NULL)
			return 0;

		int width = srcImg.cols, height = srcImg.rows;

		dstImg = Mat(height, width, CV_8UC3);

		for (int y = 0; y < width; y++)
		{
			for (int x = 0; x < height; x++)
			{
				Vec3b tmp = srcImg.at<Vec3b>(x, y);
				int b = tmp[0], g = tmp[1], r = tmp[2];

				int cmin = min(r, min(g, b));

				float h, s, v = 0.0;
				// calculate h
				float theta = acos((2 * r - g - b) / (2 * sqrt((r - g) * (r - g) + (r - b) * (g - b))));

				h = (b <= g) ? theta : (360 - theta);

				// calculate s
				s = 1 - 3 * cmin / (r + g + b);
				// calculate v
				v = (r + g + b) / 3;

				dstImg.at<Vec3b>(x, y)[0] = round(h);
				dstImg.at<Vec3b>(x, y)[1] = round(s);
				dstImg.at<Vec3b>(x, y)[2] = round(v);
			}
		}

		return 1;
	}

public:
	// 0: rgb2grayscale, 1: rgb2hsv
	int Convert(Mat& srcImg, Mat& dstImg, int type)
	{
		if (!type)
			return RGB2GrayScale(srcImg, dstImg);
		else
			return RGB2HSV(srcImg, dstImg);
	}

	
};

