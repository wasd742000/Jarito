#include "EdgeDetector.h"
#include <iostream>
using namespace std;

// square kernel matrix size
const int kSize = 3;

int EdgeDetector::DetectEdge(const Mat& sourceImage, Mat& destinationImage, int method) 
{
	// Khong phai grayscale
	if (sourceImage.channels() != 1) return 1;
	
	int nRow = sourceImage.rows;
	int nCol = sourceImage.cols;
	float eps = 1e-6;

	switch (method)
	{

	// pp Sobel
	case 1: 
	{
		float threshold = 25;

		Mat tmp = sourceImage.clone(); 
		destinationImage = Mat(nRow - kSize + 1, nCol - kSize + 1, CV_32FC1, Scalar(0));

			/*SOBEL OPERATOR MATRIX

		Gx =    [   -1   0   1  ]       Gy =    [    1    2    1   ]
				[   -2   0   2  ]               [    0    0    0   ]
				[   -1   0   1  ]               [   -1   -2   -1   ]
			*/
		vector <float> Wx = { -1 , 0, 1, -2, 0, 2, -1, 0, 1 };
		vector <float> Wy = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
		
		for (int i = 0; i < Wx.size(); i++) 
		{
			Wx[i] *= 1.0 / 4;
			Wy[i] *= 1.0 / 4;
		}
		Mat Gx;
		Mat Gy;
		Convolution ConvoX, ConvoY;
		ConvoX.SetKernel(Wx, 3, 3);
		ConvoY.SetKernel(Wy, 3, 3);
		ConvoX.DoConvolution(tmp, Gx);
		ConvoY.DoConvolution(tmp, Gy);

		for (int i = 0; i < destinationImage.rows; i++)
			for (int j = 0; j < destinationImage.cols; j++) 
			{
				float fx = Gx.ptr<float>(i)[j];
				float fy = Gy.ptr<float>(i)[j];
				float e = sqrt(fx * fx + fy * fy);
				if (e - threshold >= eps) 
					destinationImage.ptr<float>(i)[j] = 1;
			}
	}
		  break;

	// pp Prewitt
	case 2: 
	{
		
		float threshold = 50;

		Convolution ConvOx, ConvOy;
		Mat fx;
		Mat fy;

		/*Prewitt OPERATOR MATRIX

		Gx =    [   1   0   -1  ]       Gy =    [   -1    -1    -1   ]
				[   1   0   -1  ]               [   0      0     0   ]
				[   1   0   -1  ]               [	1	   1	 1   ]
			*/
		vector <float> Wx = { 1.0, 0, -1.0, 1.0, 0, -1.0, 1.0, 0, -1.0 };
		vector <float> Wy = { -1.0, -1.0, -1.0, 0, 0, 0, 1.0, 1.0, 1.0 };

		for (int i = 0; i < Wx.size(); i++) 
		{
			Wx[i] *= 1.0 / 3;
			Wy[i] *= 1.0 / 3;
		}

		ConvOx.SetKernel(Wx, kSize, kSize);
		ConvOx.DoConvolution(sourceImage, fx);

		ConvOy.SetKernel(Wy, kSize, kSize);
		ConvOy.DoConvolution(sourceImage, fy);

		destinationImage = Mat(nRow - kSize + 1, nCol - kSize + 1, CV_32FC1, Scalar(0));
		for (int i = 0; i < destinationImage.rows; i++)
		{
			float* DestRow = destinationImage.ptr<float>(i);
			float* fxRow = fx.ptr<float>(i);
			float* fyRow = fy.ptr<float>(i);
			for (int j = 0; j < destinationImage.cols; j++) 
			{
				float e = sqrt(fxRow[j] * fxRow[j] + fyRow[j] * fyRow[j]);
				if (e - threshold >= eps) 
					DestRow[j] = 1;
			}
		}
		fx.release();
		fy.release();
	}
		  break;

	// em chua lam xong pp laplace 
	case 3: 
	{
	}
		  break;
	}


	return 0;
}

EdgeDetector::EdgeDetector() {
}

EdgeDetector::~EdgeDetector() {
}