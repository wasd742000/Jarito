#include <iostream>
#include <String.h> 
#include "opencv2/highgui/highgui.hpp"

#include "ColorTransformer.h"
#include "Converter.h"



using namespace cv;

void paraError() {
	std::cout << "Parameters Error !!" << std::endl;
}


int main(int argc, char** argv)
{
	Converter CV;
	ColorTransformer CT;

	String input, output;

	if (argc == 4)
	{
		
		input = argv[2]; output = argv[3];
		if (strcmp(argv[1], "-rgb2gray") == 0)
		{
			Mat srcImage = imread(input, IMREAD_COLOR);
			Mat dstImage;
			CV.Convert(srcImage, dstImage, 0);
			imwrite(output, dstImage);
		}
		else if (strcmp(argv[1], "-rgb2hsv") == 0)
		{
			Mat srcImage = imread(input, IMREAD_COLOR);
			Mat dstImage;
			CV.Convert(srcImage, dstImage, 1);
			imwrite(output, dstImage);
		}
		else if (strcmp(argv[1], "-drawhist") == 0)
		{
			Mat srcImage = imread(input, IMREAD_GRAYSCALE);
			Mat histMat, dstImage;
			CT.CalcHistogram(srcImage, histMat);
			CT.DrawHistogram(histMat, dstImage);
			imwrite(output, dstImage);
		}
		else if (strcmp(argv[1], "-equalhist") == 0)
		{
			Mat srcImage = imread(input, IMREAD_GRAYSCALE);
			Mat dstImage;
			CT.HistogramEqualization(srcImage, dstImage);
			imwrite(output, dstImage);
		}
		else
			paraError();

	}
	else if (argc == 5)
	{
		input = argv[3]; output = argv[4];
		if (strcmp(argv[1], "-bright") == 0)
		{
			long b = strtol(argv[2], NULL, 10);
			Mat srcImage = imread(input, IMREAD_COLOR);
			Mat dstImage;
			CT.ChangeBrighness(srcImage, dstImage, b);
			imwrite(output, dstImage);
		}
		else if (strcmp(argv[1], "-contrast") == 0)
		{
			long c = strtol(argv[2], NULL, 10);
			Mat srcImage = imread(input, IMREAD_COLOR);
			Mat dstImage;
			CT.ChangeContrast(srcImage, dstImage, c);
			imwrite(output, dstImage);
		}
		else
			paraError();
	}
	else
		paraError();


	//waitKey(0);
	return 0;

}
