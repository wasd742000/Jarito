#pragma once
#include <math.h> 
#include "opencv2/opencv.hpp"

using namespace cv;

class ColorTransformer
{
public:

	int ChangeBrighness(const Mat& srcImg, Mat& dstImg, short b)
	{
		if (srcImg.data == NULL)
			return 0;

		int width = srcImg.cols, height = srcImg.rows;

		if (srcImg.channels() == 1) // Grayscale
			dstImg = Mat(height, width, CV_8UC1);
		else if (srcImg.channels() == 3) // RGB 
			dstImg = Mat(height, width, CV_8UC3);

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				// Grayscale
				if (srcImg.channels() == 1)
				{
					if (srcImg.at<uchar>(x, y) + b > 255)
						dstImg.at<uchar>(x, y) = 255;
					else if (srcImg.at<uchar>(x, y) + b < 0)
						dstImg.at<uchar>(x, y) = 0;
					else
						dstImg.at<uchar>(x, y) = srcImg.at<uchar>(x, y) + b;
				}

				// RGB
				else if (srcImg.channels() == 3)
				{
					for (int i = 0; i < 3; i++)
					{
						if (srcImg.at<Vec3b>(x, y)[i] + b > 255)
							dstImg.at<Vec3b>(x, y)[i] = 255;
						else if (srcImg.at<Vec3b>(x, y)[i] + b < 0)
							dstImg.at<Vec3b>(x, y)[i] = 0;
						else
							dstImg.at<Vec3b>(x, y)[i] = srcImg.at<Vec3b>(x, y)[i] + b;
					}
				}
			}
		}
		return 1;
	}


	int ChangeContrast(const Mat& srcImg, Mat& dstImg, float c)
	{
		if (srcImg.data == NULL)
			return 0;

		int width = srcImg.cols, height = srcImg.rows;
		float factor = 259 * (c + 255) / (255 * (259 - c));


		if (srcImg.channels() == 1) // Grayscale
			dstImg = Mat(height, width, CV_8UC1);
		else if (srcImg.channels() == 3) // RGB 
			dstImg = Mat(height, width, CV_8UC3);

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				// Grayscale
				if (srcImg.channels() == 1)
					dstImg.at<uchar>(x, y) = trunc(factor * (srcImg.at<uchar>(x, y) - 128) + 128);

				// RGB
				else if (srcImg.channels() == 3)
				{
					for (int i = 0; i < 3; i++)
						dstImg.at<Vec3b>(x, y)[i] = trunc(factor * (srcImg.at<Vec3b>(x, y)[i] - 128) + 128);
				}
			}
		}
		return 1;
	}


	int CalcHistogram(const Mat& srcImg, Mat& histMat)
	{
		if (srcImg.data == NULL)
			return 0;

		int width = srcImg.cols, height = srcImg.rows;


		if (srcImg.channels() == 1) // Grayscale
			histMat = Mat::zeros(1, 256, CV_32FC1);
		else if (srcImg.channels() == 3) // RGB 
			histMat = Mat::zeros(3, 256, CV_32FC1);

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				// Grayscale
				if (srcImg.channels() == 1)
				{
					uchar pixel_value = srcImg.at<uchar>(x, y);
					histMat.at<float>(pixel_value) += 1;
				}
				// RGB
				else if (srcImg.channels() == 3)
				{
					// for each channel rgb
					for (int i = 0; i < 3; i++)
					{
						uchar pixel_value = srcImg.at<Vec3b>(x, y)[i];
						histMat.at<float>(i, pixel_value) += 1;
					}
				}
			}
		}
		return 1;
	}

	// find max for hist matrix, mode(0 - gray, 1 - rgb)
	int histmatMax(const Mat& histMat, bool mode)
	{
		if (histMat.data == NULL)
			return 0;

		int max;
		// Grayscale
		if (!mode)
		{
			max = histMat.at<float>(0);
			for (int i = 0; i < 256; i++)
				if (histMat.at<float>(i) > max)
					max = histMat.at<float>(i);
		}
		// RGB
		else
		{
			max = histMat.at<float>(0, 0);
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 256; j++)
					if (histMat.at<float>(i, j) > max)
						max = histMat.at<float>(i, j);
		}

		return max;
	}

	int HistogramEqualization(const Mat& srcImg, Mat& histImg)
	{
		if (srcImg.data == NULL)
			return 0;

		Mat histMat;
		CalcHistogram(srcImg, histMat);

		if (histMat.rows == 1)
		{
			// Tich luy
			Mat tmp = Mat::zeros(1, 256, CV_32FC1);
			tmp.at<float>(0) = histMat.at<float>(0);
			for (int i = 1; i < 256; i++)
				tmp.at<float>(i) = tmp.at<float>(i - 1) + histMat.at<float>(i);


			// Chuan hoa
			for (int i = 0; i < 256; i++)
				tmp.at<float>(i) = round((255 * tmp.at<float>(i) / (srcImg.rows * srcImg.cols)));

			histImg = Mat(srcImg.rows, srcImg.cols, CV_8UC1);
			for (int y = 0; y < srcImg.rows; y++)
			{
				for (int x = 0; x < srcImg.cols; x++) {
					histImg.at<uchar>(x, y) = trunc(tmp.at<float>(srcImg.at<uchar>(x, y)));
				}
			}

		}
		// RGB - error
		else if (histMat.rows == 3)
		{
			// Tich luy
			Mat tmp = Mat::zeros(3, 256, CV_32FC1);

			// Lan luot 3 channels
			for (int j = 0; j < 3; j++)
			{

				tmp.at<float>(j, 0) = histMat.at<float>(j, 0);

				for (int i = 1; i < 256; i++)
					tmp.at<float>(j, i) = tmp.at<float>(j, i - 1) + histMat.at<float>(j, i);

				// Chuan hoa
				for (int i = 0; i < 256; i++)
					tmp.at<float>(j, i) = round((255 * tmp.at<float>(j, i) / (srcImg.rows * srcImg.cols)));

				histImg = Mat(srcImg.rows, srcImg.cols, CV_8UC3);
				for (int y = 0; y < srcImg.rows; y++)
				{
					for (int x = 0; x < srcImg.cols; x++)
						histImg.at<Vec3b>(x, y)[j] = trunc(tmp.at<float>(j, srcImg.at<uchar>(x, y)));
				}
			}

		}
		return 1;
	}


	int DrawHistogram(const Mat& histMat, Mat& histImg)
	{

		if (histMat.data == NULL)
			return 0;

		int hist_thick = 15;

		// gray scale histogram
		if (histMat.size[0] == 1)
		{
			int hist_max = histmatMax(histMat, 0);
			histImg = Mat(hist_max, 255 * hist_thick, CV_8UC1);
			Mat nom;
			normalize(histMat, nom, 0, hist_max, NORM_MINMAX, -1, Mat());

			for (int i = 0; i < 256; i++)
			{
				rectangle(histImg, Point(2 * i, histImg.rows - nom.at<float>(i)),
					Point(2 * (i + 1), histImg.rows), Scalar(i));
				//namedWindow("Histogram", WINDOW_NORMAL);
				//imshow("Histogram", histImg);
			}
		}

		// RGB
		else if (histMat.size[0] == 3)
		{
			/*int hist_max = histmatMax(histMat, 1);

			for (int j = 0; j < 3; j++)
			{
				histImg = Mat(hist_max, 255 * hist_thick, CV_8UC1);
				Mat nom;
				Mat tmp = Mat::zeros(1, 256, CV_32FC1);
				for (int z = 0; z < 256; z++)
					tmp.at<float>(z) = histMat.at<float>(j, z);

				normalize(tmp, nom, 0, hist_max, NORM_MINMAX, -1, Mat());

				for (int i = 0; i < 256; i++)
				{
					if (j == 0)
					{
						rectangle(histImg, Point(2 * i, histImg.rows - nom.at<float>(i)),
							Point(2 * (i + 1), histImg.rows), Scalar(0, 0, i));
						namedWindow("Histogram B", WINDOW_NORMAL);
						imshow("Histogram B", histImg);
					}

					else if (j == 1)
					{
						rectangle(histImg, Point(2 * i, histImg.rows - nom.at<float>(i)),
							Point(2 * (i + 1), histImg.rows), Scalar(0, i, 0));
						namedWindow("Histogram G", WINDOW_NORMAL);
						imshow("Histogram G", histImg);
					}
					else if (j == 2)
					{
						rectangle(histImg, Point(2 * i, histImg.rows - nom.at<float>(i)),
							Point(2 * (i + 1), histImg.rows), Scalar(i, 0, 0));
						namedWindow("Histogram R", WINDOW_NORMAL);
						imshow("Histogram R", histImg);
					}

				}
			}*/
		}
	}

	
};

