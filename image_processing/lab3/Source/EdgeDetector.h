﻿#pragma once
#include "opencv2/opencv.hpp"
#include "Convolution.h"

using namespace cv;


class EdgeDetector
{
public:
	/*
	Hàm phát hiện biên cạnh của ảnh xám
	sourceImage: ảnh input
	destinationImage: ảnh output
	method: phương pháp detect
		1: Sobel
		2: Prewitt
		3: Laplace
	Hàm trả về
		0: nếu detect thành công
		1: nếu detect thất bại (không đọc được ảnh input,...)
	*/
	int DetectEdge(const Mat& sourceImage, Mat& destinationImage, int method);
	EdgeDetector();
	~EdgeDetector();
};

