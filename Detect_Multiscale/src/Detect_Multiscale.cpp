//============================================================================
// Name        : Detect_Multiscale.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main() {
	VideoCapture cap("tra3.mp4"); // open the default camera
	if (!cap.isOpened()) {
		cout << "HI"; // check if we succeeded

		return -1;
	}
	Mat img;
	CascadeClassifier cascade;
	for (;;) {

		cap >> img; // get a new frame from camera


		cvtColor(img, img, IMREAD_GRAYSCALE);

		//imwrite(format("DNG_fr_cam_%d.jpg", i).c_str(), img);
		//namedWindow("Image", CV_WINDOW_NORMAL);
		//imshow("Image", img);

		if (cascade.load("cascade_new.xml")) {
			vector<Rect> faces;
			//cascade.detectMultiScale(img, faces, 4.1, 3, CV_HAAR_DO_CANNY_PRUNING, Size(30, 30), Size(200, 200));
			cascade.detectMultiScale(img, faces, 1.05, 3,
					4, Size(10, 10),
					Size(300, 300));
			Mat pic=img;
			//	printf("%zd face(s) are found.\n", faces.size());

			for (int j = 0; j < faces.size(); j++) {

				Rect r = faces[j];
				//	printf("a face is found at Rect(%d,%d,%d,%d).\n", r.x, r.y,
				//			r.width, r.height);
				rectangle(pic, r, 1, 8, 0);
				namedWindow("Number", CV_WND_PROP_ASPECTRATIO);
				imshow("Number", pic);
				//while(waitKey(30)>=0) break;
				while (waitKey(30)!=27);
				//pic=img(faces[j]);

				//imwrite(format("result2/NG_fr_cam_%d.jpg", i*10+j).c_str(), pic);


			}
//			namedWindow("Number", CV_WND_PROP_ASPECTRATIO);
//			imshow("Number", pic);
//			//while(waitKey(30)>=0) break;
//			waitKey(1);

		}

	}
	return 0;
}
