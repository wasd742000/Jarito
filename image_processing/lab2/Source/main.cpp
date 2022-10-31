#include <iostream>
#include "opencv2/opencv.hpp"
#include "GeometricTransformer.h"


using namespace cv;
//const float PI = 3.1415926;

void paraError() {
	std::cout << "Parameters Error !!" << std::endl;
	exit(0);
}


int main(int argc, char** argv)
{
	GeometricTransformer GT;
	PixelInterpolate* pix;
	

	String input, output;

	// Flip
	if (argc == 5)
	{
		if (strcmp(argv[2], "-bl"))
			pix = new BilinearInterpolate();
		else if (strcmp(argv[2], "-nn"))
			pix = new NearestNeighborInterpolate();
		else
			paraError();
		
		input = argv[3]; output = argv[4];
		Mat srcImage = imread(input, IMREAD_COLOR);
		Mat dstImage;
		if (strcmp(argv[1], "-flipV") == 0)
		{
			GT.Flip(srcImage, dstImage, 0, pix);
			imwrite(output, dstImage);
		}
		else if (strcmp(argv[1], "flipH") == 0)
		{
			GT.Flip(srcImage, dstImage, 1, pix);
			imwrite(output, dstImage);
		}
		else
			paraError();
	}
	// Rotate
	else if (argc == 6)
	{
		if (strcmp(argv[2], "-bl"))
			pix = new BilinearInterpolate();
		else if (strcmp(argv[2], "-nn"))
			pix = new NearestNeighborInterpolate();
		else
			paraError();

		input = argv[4]; output = argv[5];
		Mat srcImage = imread(input, IMREAD_COLOR);
		Mat dstImage;
		long angle = strtol(argv[3], NULL, 10);
		if (strcmp(argv[1], "-rotK") == 0)
		{
			GT.RotateKeepImage(srcImage, dstImage, angle, pix);
			imwrite(output, dstImage);
		}
		else if (strcmp(argv[1], "-rotP") == 0)
		{
			GT.RotateUnkeepImage(srcImage, dstImage, angle, pix);
			imwrite(output, dstImage);
		}
		else
			paraError();
	}
	// Zoom, resize
	else if (argc == 7)
	{
		if (strcmp(argv[2], "-bl"))
			pix = new BilinearInterpolate();
		else if (strcmp(argv[2], "-nn"))
			pix = new NearestNeighborInterpolate();
		else
			paraError();

		input = argv[5]; output = argv[6];
		Mat srcImage = imread(input, IMREAD_COLOR);
		Mat dstImage;
		long p1 = strtol(argv[3], NULL, 10);
		long p2 = strtol(argv[4], NULL, 10);
		if (strcmp(argv[1], "-zoom") == 0)
		{
			GT.Scale(srcImage, dstImage, p1, p2, pix);
			imwrite(output, dstImage);
		}
		else if (strcmp(argv[1], "-resize") == 0)
		{
			GT.Resize(srcImage, dstImage, p1, p2, pix);
			imwrite(output, dstImage);
		}
		else
			paraError();
	}
	else
		paraError();

	return 0;

}
