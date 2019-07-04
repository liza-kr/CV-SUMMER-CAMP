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
"{ w  width                             |    124    | image width for classification    }"
"{ h  height                            |     124   | image heigth fro classification   }"
"{ model_path                           |    C:\\Users\\temp2019\\Desktop\\CV Camp\\classification\\squeezenet\\1.1\\caffe    | path to model                     }"
"{ config_path                          |    C:\\Users\\temp2019\\Desktop\\CV Camp\\classification\\squeezenet\\1.1\\caffe   | path to model configuration       }"
"{ label_path                           |    C:\\Users\\temp2019\\Desktop\\CV Camp\\CV-SUMMER-CAMP\\data    | path to class labels              }"
"{ mean                                 |    <none>    | vector of mean model values       }"
"{ swap                                 |    FALSE    | swap R and B channels. TRUE|FALSE }"
"{ q ? help usage                       |        | print help message                }";

int main(int argc, char** argv)
{
	// Process input arguments
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

	int width = parser.get<int>("w");
	int height = parser.get<int>("h");
	string model_path = parser.get<string>("model_path");
	string config_path = parser.get<string>("config_path");

	DnnClassificator clas;
	//Image classification
	clas.DnnClassificator();
	clas.Classify(image);

	//Show result


	return 0;
}
