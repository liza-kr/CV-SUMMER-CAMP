#include "classificator.h"

DnnClassificator::DnnClassificator(float inputWidth, float inputHeight, string model, string config, string label, Scalar meann, bool swap)
{
	width= inputWidth;
	height= inputHeight;
	model_path= model;
	config_path= config;
	label_path= label;
	mean= meann;
	SwapRB= swap;
	net = readNet(model_path,config_path);
	net.setPreferableBackend(0);
	net.setPreferableTarget(0);
}

Mat DnnClassificator::Classify(Mat image) {
	Mat inputTensor;
	blobFromImage(image, inputTensor, 0.00833, Size(width, height), mean, SwapRB,CV_8UC3);
	net.setInput(inputTensor);
	Mat result = net.forward();
	return result;
}