#include "./opencv2/opencv.hpp"
//#include "./opencv2/opencv.hpp"
#include "./opencv/highgui.h"
#include <iostream>

using namespace std;

int main(int argc,char *argv[])
{

	cv::VideoCapture capture(-1);

	if (!capture.isOpened())
		cout << "Web cam is not opened!"<<endl;
	else
		cout << "Web cam is opened!" << endl;

	cv::namedWindow("EX3",1);
	cv::CascadeClassifier face_classifier;
	cv::CascadeClassifier eye_classifier;
	face_classifier.load("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml");
	eye_classifier.load("/usr/local/share/OpenCV/haarcascades/haarcascade_eye.xml");
	while (true)
	{
		bool frame_valid = true;

		cv::Mat frame_ori;
		cv::Mat frame;

		try
		{
			capture >>frame_ori;
			cv::resize(frame_ori,frame,cv::Size(frame_ori.cols/2,frame_ori.rows/2),0,0,CV_INTER_NN);	
		}
		catch(cv::Exception & e)
		{
			cerr <<"Exception occured!"<<endl;
			frame_valid = false;
		}

		if(frame_valid)
		{
			try
			{

				cv::Mat grayframe;
				cv::cvtColor(frame,grayframe,CV_BGR2GRAY);
				cv::equalizeHist(grayframe,grayframe);

				vector<cv::Rect> faces;
				face_classifier.detectMultiScale(grayframe,faces,1.1,3,CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_SCALE_IMAGE,cv::Size(30,30));
				int i = 0;
				for (i = 0; i<faces.size();i++)
				{
					cv::Point lb(faces[i].x +faces[i].width,
							faces[i].y + faces[i].height);
					cv::Point tr(faces[i].x,faces[i].y);
					cv::rectangle(frame,lb,tr,cv::Scalar(0,255,0),3,4,0);
				}

				cv::imshow("webcam",frame);
			}
			catch(cv::Exception&e)
			{
				cerr <<"Exception occured. face"<<endl;
			}
		}
		if(cv::waitKey(30)>=0)
			break;
	}

	return 0;
}
