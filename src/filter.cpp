#include "filter.h"

Mat GrayFilter::ProcessImage(Mat image)
{
	Mat img;
	cvtColor(image, img, COLOR_BGR2GRAY);
	return img;
}

ResizeFilter::ResizeFilter(int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
}

Mat ResizeFilter::ProcessImage(Mat image)
{
	Mat img;// (width, height, CV_8UC3);
	cv::resize(image, img, Size(width, height));
	return img;
}