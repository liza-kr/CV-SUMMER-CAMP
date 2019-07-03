#include "filter.h"

Mat GrayFilter::ProcessImage(Mat image)
{
	cv::cvtColor(image, image, CV_8UC1);

}