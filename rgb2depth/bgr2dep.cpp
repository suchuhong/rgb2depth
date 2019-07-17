#include <iostream>
#include <fstream>
#include <sstream>

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	for (int num = 1; num < 300; num++)
	{
		char depthToBgrabuff[256];
		sprintf_s(depthToBgrabuff, "depth2bgra//depthToBgra%d.jpg", num);//depth2bgra路径
		char depthbuff[256];
		sprintf_s(depthbuff, "depth//depth%d.png", num);//depth路径

		Mat depthToBgra2 = imread(depthToBgrabuff, -1);
		Mat depth2 = imread(depthbuff, -1);
		Mat depthToBgra;
		depthToBgra2.copyTo(depthToBgra);


		for (int i = 0; i < depth2.rows; i++)
			for (int k = 0; k < depth2.cols; k++) {
				unsigned int d = depth2.ptr<unsigned short>(i)[k];//使用 ptr不会报错
				if (d > 1500 || d == 0)
					for (int j = 0; j < 3; j++)
						depthToBgra.at<Vec3b>(i, k)[j] = 0;
			}

		char bgrBuff[256];
		sprintf_s(bgrBuff, "bgr//bgr%d.jpg", num);//保存路径
		imwrite(bgrBuff,depthToBgra);
		if (num % 15 == 0) {
			imshow(bgrBuff, depthToBgra);
			waitKey(5000);
			destroyAllWindows();
		}
		
	}
	
	return 0;
}