#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "filter.h"

using namespace cv;
using namespace std;

const char* cmdAbout = "Sample of OpenCV usage. ";

const char* cmdOptions =
"{ i  image         | <none> | image to process        }"
"{ w  width         | 500 | width for image resize  }"
"{ h  height        | 500 | height for image resize }"
"{ q ? help usage   | <none> | print help message      }";

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

	int width = parser.get<int>("w");
	int height = parser.get<int>("h");


    // Load image

	Mat frame;//aditional exercize ¹1
	VideoCapture cap(1);
	while (waitKey(1) < 0)
	{
		cap >> frame;
		if (frame.empty())
		{
			
			String imgName(parser.get<String>("image"));
			Mat image = imread(imgName);

			// Filter image
			GrayFilter img;
			Mat imag = img.ProcessImage(image);



			// Show image
			imshow("My image", imag);
			waitKey();

			ResizeFilter im = ResizeFilter(width, height);
			Mat imagenew = im.ProcessImage(image);

			imshow("My image", imagenew);
			waitKey();
			break;
		}
		imshow("frame", frame);
	}
    return 0;
}
