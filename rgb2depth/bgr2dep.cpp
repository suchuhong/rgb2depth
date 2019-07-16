#include <iostream>
#include <fstream>
#include <sstream>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat img = imread("depth//depthToBgra17.jpg", -1);

	return 0;
}