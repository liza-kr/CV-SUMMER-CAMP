#include "classificator.h"

DnnClassificator::DnnClassificator() {
	string model = string(argv[1]);
	string config = string(argv[2]);
	string label = string(argv[3]);
	int width = 120;
	int height = 140;
	Scalar mean = Scalar (0);
	string swarpRB = false;
	Net net = readNet(model, config);
	net.setPreferableBackend(0);
	net.setPreferableTarget(0);
}

Mat DnnClassificator::Classify(Mat image) {
	Net blobFromImage(image, blob, 3, Size(width, height), mean, swarpRB, false);
	net.setInput(blob);
	Mat prob = net.forward();
	Point classIdPoint;
	double confidence;
	minMaxLoc(prob.reshape(1, 1), 0, &confidence, 0, &classIdPoint);
	int classId = classIdPoint.x;
	cout << "class: " << classId << '\n';
	cout << "Confidence: " << confidence << '\n';
}