#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("etest.jpg", 1);
	cv::Mat resMat;

	cv::Mat src_channels[3];
	cv::Mat res_channels[3];

	//对图像进行通道分离
	split(srcMat, src_channels);

	//对每个通道进行直方图均衡
	for (int i = 0; i <= 2; i++)
	{
		equalizeHist(src_channels[i], res_channels[i]);	
	}

	//对图像进行通道合并
	merge(res_channels, 3, resMat);

	imshow("srcMat", srcMat);
	imshow("resMat", resMat);

	waitKey(0);
	return 0;
}

