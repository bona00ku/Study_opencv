#include <iostream>
//#include <opencv2/opencv.hpp>
#include "./opencv2/opencv.hpp"
using namespace std;
int main()
{

	std::cout << "OpenCV Version : " << CV_VERSION << std::endl;

	cv::Mat img;
	cv::namedWindow("EX2",1);
	cv::VideoCapture cap;
	cap.open(1);

	while(cap.isOpened())
	{
		//cout << "CAP is opened!"<<endl;
		cap >> img;
		cv::imshow("EX2",img);
		if(cv::waitKey(30) == 27)
			break;
	}
	cv:: destroyWindow("EX2");
	return 0;
}
		
