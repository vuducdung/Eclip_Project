#include "opencv2/opencv.hpp"
#include<iostream>
#include<string>

using namespace cv;
using namespace std;

int main(int, char**) {
	//VideoCapture cap("LẠC TRÔI  OFFICIAL MUSIC VIDEO  SƠN TÙNG M-TP.mp4"); // open the default camera
	VideoCapture cap("VIDEO0039.mp4"); // open the default camera
	if (!cap.isOpened()) {
		cout << "HI"; // check if we succeeded
		return -1;
	}

	Mat edges;
	 for( int i=0;;i++){
		Mat frame;
		cap >> frame; // get a new frame from camera

		if (i % 5 == 0) {
			cvtColor(frame, edges, COLOR_RGB2RGBA);

            imwrite(format( "bien_vuong_%d.jpg", i ).c_str(), edges);

			namedWindow("edges", CV_WINDOW_NORMAL);
			imshow("edges", edges);

			while(waitKey(30)!=27);
		}
	}
return 0;

}

