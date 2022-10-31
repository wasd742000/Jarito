#include "opencv2\core.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2\highgui\highgui.hpp"
#include <iostream>
#include <string.h>	
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{

	Mat image;
	image = imread(argv[1]);
	//image = imread("lenna.jpg", IMREAD_COLOR);
	if (!image.data)
	{
		cout << "Khong the mo anh" << std::endl;
		return -1;
	}

	// chuyen sang anh grayscale
	if (argc == 3 && !strcmp(argv[2], "-convertColor"))
	{	
		cvtColor(image, image, COLOR_BGR2GRAY);
	}
	else if (argc == 4)
	{
		//newImg = Mat(image.rows, image.cols, CV_8UC3);
		// lay gia tri thay doi
		stringstream s(argv[3]);
		int c;
		s >> c;
		// thay doi do sang anh
		if (!strcmp(argv[2], "-brightness"))
			image.convertTo(image, -1, 1, c);
		// thay doi tuong phan anh
		if (!strcmp(argv[2], "-constrast"))
			image.convertTo(image, -1, c, 0);
	}
	imshow("result", image);
	waitKey(0);
	return 0;
}


//#include <iostream>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//
//int main(int argc, char** argv)
//{
//	char* path = new char[30];
//	cout << "image path: "; cin >> path;
//	Mat img;
//	img = imread(path, IMREAD_COLOR);
//	if (img.empty())
//	{
//		cout << "Could not find any image !" << endl;
//		return -1;
//	}
//	namedWindow("demo", WINDOW_AUTOSIZE);
//	imshow("demo", img);
//	waitKey(0);
//
//	return 0;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
