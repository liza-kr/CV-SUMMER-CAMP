#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "classificator.h"

using namespace cv;
using namespace std;

const char* cmdAbout = "Sample of OpenCV usage. ";

const char* cmdOptions =
"{ i  image                             | <none> | image to process                  }"
"{ w  width                             |   512  | image width for classification    }"
"{ h  height                            |   256  | image heigth fro classification   }"
"{ model_path                           |    C:\\My foulder\\Resourses\\classification\\squeezenet\\1.1\\caffe    | path to model                     }"
"{ config_path                          |    C:\\My foulder\\Resourses\\classification\\squeezenet\\1.1\\caffe   | path to model configuration       }"
"{ label_path                           |        | path to class labels              }"
"{ mean                                 |        | vector of mean model values       }"
"{ swap                                 |        | swap R and B channels. TRUE|FALSE }"
"{ q ? help usage                       |        | print help message                }";

int main(int argc, char** argv)
{
	//Process input arguments
	CommandLineParser parser(argc, argv, cmdOptions);
	parser.about(cmdAbout);

	if (parser.has("help"))
	{
		parser.printMessage();
		return 0;
	}
	if (!parser.check())
	{
		parser.printErrors();
		return 0;
	}

	// Load image and init parameters
	String imgName(parser.get<String>("image"));
	cv::Mat image = cv::imread(imgName);

	float width = parser.get<float>("w");
	float height = parser.get<float>("h");
	string model_path(parser.get<string>("model_path"));
	string config_path(parser.get<string>("config_path"));
	string label_path="C:\\My foulder\\Resourses\\classification\\squeezenet\\1.1\\caffe";
	//string mean(parser.get<string>("mean "));
	bool SwapRB=false;
	

	Scalar mean = { 113,123,124 };

	//Image classification
	DnnClassificator classify = DnnClassificator(width, height, model_path, config_path, label_path, mean, SwapRB);
	Mat result = classify.Classify(image);

	//Show result
	Point classIdPoint;
	double confidence;
	minMaxLoc(result.reshape(1, 1), 0, &confidence, 0, &classIdPoint);
	int classId = classIdPoint.x;
	cout << "Class: " << classId << '\n';
	cout << "Confidence: " << confidence << '\n';

	return 0;
}
