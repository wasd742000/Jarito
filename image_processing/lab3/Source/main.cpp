#include <iostream>
#include "opencv2/opencv.hpp"
#include "Blur.h"
#include "EdgeDetector.h"


using namespace cv;

void paraError()
{
	std::cout << "Parameters Error ! \nUse \"Lab3_XLAV.exe -help \" for more instruction. \n" << std::endl;
	exit(0);
}

// Huong dan
void instruction()
{
	std::cout << "______________________________Cu phap command__________________________________\n";
	std::cout << "\nBlur methods:\n___________________________________________________________________\n";
	std::cout << "1) Average filtering: <Program.exe> -avg <kx> <ky> <InputFilePath> <OutputFilePath>\n";
	std::cout << "2) Median filtering: <Program.exe> -med <kx> <ky> <InputFilePath> <OutputFilePath>\n";
	std::cout << "3) Gaussian filtering: <Program.exe> -gau <kx> <ky> <InputFilePath> <OutputFilePath>\n";
	std::cout << "\nEdge detection methods:\n___________________________________________________________________\n";
	std::cout << "1) Sobel operator: <Program.exe> -sobel <InputFilePath> <OutputFilePath>\n";
	std::cout << "2) Prewitt operator: <Program.exe> -prew <InputFilePath> <OutputFilePath>\n";
	std::cout << "3) Laplace operator: <Program.exe> -lap <InputFilePath> <OutputFilePath>\n";

	exit(0);
}


int main(int argc, char** argv)
{
	Mat srcImg, dstImg;
	int flag = 1;
	String inputFile, outputFile;

	Blur blurMethod;
	EdgeDetector edgeDetectMethod;

	if (argc == 2 && strcmp(argv[1], "-help") == 0)
		instruction();

	// Phat hien bien canh
	else if (argc == 4)
	{
		inputFile = argv[2]; outputFile = argv[3];
		srcImg = imread(inputFile, IMREAD_GRAYSCALE);

		if (srcImg.empty())
		{
			std::cout << "Image Not Found!!!\n";
			exit(0);
		}

		if (strcmp(argv[1], "-sobel") == 0)
			flag = edgeDetectMethod.DetectEdge(srcImg, dstImg, 1);
		else if (strcmp(argv[1], "-prew") == 0)
			flag = edgeDetectMethod.DetectEdge(srcImg, dstImg, 2);
		else if (strcmp(argv[1], "-lap") == 0)
		{
			std::cout << "Em chua hoan thanh phat hien bien canh = Laplace operator!\n";
			exit(0);
		}
		else
			paraError();

		imwrite(outputFile, dstImg);

	}
	// Lam tron anh Average filter, median filtering, gaussian filtering
	else if (argc == 6)
	{
		inputFile = argv[4]; outputFile = argv[5];
		srcImg = imread(inputFile, IMREAD_GRAYSCALE);

		if (srcImg.empty())
		{
			std::cout << "Image Not Found!!!\n";
			exit(0);
		}

		int kX = atoi(argv[2]), kY = atoi(argv[3]);

		if (strcmp(argv[1], "-avg") == 0)
			flag = blurMethod.BlurImage(srcImg, dstImg, kX, kY, 0);
		else if (strcmp(argv[1], "-med") == 0)
			flag = blurMethod.BlurImage(srcImg, dstImg, kX, kY, 1);
		else if (strcmp(argv[1], "-gau") == 0)
			flag = blurMethod.BlurImage(srcImg, dstImg, kX, kY, 2);
		else
			paraError();

		imwrite(outputFile, dstImg);

	}
	else
		paraError();


	if (flag)
		std::cout << " Program fail ! (image not find / can not read image / other problems ...)";
	/*else
	{
		imshow("Source Image", srcImg);
		imshow("Result Image", dstImg);
		waitKey(0);
	}*/

	return 0;

}
