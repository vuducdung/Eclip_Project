//============================================================================
// Name        : Detect_Multiscale.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;
int main () {
	Mat img = imread("test_img.png");
	namedWindow("Number1",CV_WINDOW_NORMAL);
	imshow("Number1",img);
	while(waitKey(30)!=27);
	CascadeClassifier cascade;
	if (cascade.load("vi_biendai_20151209.xml")) {
		vector<Rect> faces;
		//cascade.detectMultiScale(img, faces, 4.1, 3, CV_HAAR_DO_CANNY_PRUNING, Size(30, 30), Size(200, 200));
		cascade.detectMultiScale(img, faces, 1.1, 3, CV_HAAR_FIND_BIGGEST_OBJECT, Size(0, 0), Size(300,300));

		printf("%zd face(s) are found.\n", faces.size());

		for (int i = 0; i < faces.size(); i++) {
			Rect r = faces[i];
			printf("a face is found at Rect(%d,%d,%d,%d).\n", r.x, r.y, r.width, r.height);
			rectangle(img,r,1,8,0);
			namedWindow("Number",CV_WINDOW_NORMAL);
			imshow("Number",img);
			while(waitKey(30)!=27);
		}
	}

	return 0;
}
