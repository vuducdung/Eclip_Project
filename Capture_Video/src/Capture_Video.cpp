//============================================================================
// Name        : Capture_Video.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
  Mat image;
  image=imread( "dog.jpg",IMREAD_GRAYSCALE);
  namedWindow( "Dog", CV_WINDOW_AUTOSIZE );
  imshow( "Dog", image );
  while(waitKey(30)!=27);
  return 0;
}
