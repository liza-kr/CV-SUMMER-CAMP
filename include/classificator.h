#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace cv::dnn;
using namespace std;

class Classificator
{
private:
	
public:
    vector<string> classesNames;
    virtual Mat Classify(Mat image) = 0 {}
};

class DnnClassificator:public Classificator {
private:
	float width;
	float height;
	string model_path;
	string config_path;
	string label_path;
	Scalar mean;
	bool SwapRB;
	Net net;
public:
	DnnClassificator( float inputWidth, float inputHeight, string model, string config, string label, Scalar meann, bool swap);
	Mat Classify(Mat image);
};