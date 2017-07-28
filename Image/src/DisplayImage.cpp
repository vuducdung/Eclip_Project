/*
 * DisplayImage.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: dung
 */
#include <cv.h>
#include <highgui.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main( int argc, char** argv )
{
  Mat image;
  image = imread( "dog.jpg" );

  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }

  namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
  imshow( "Display Image", image );

  waitKey(0);

  return 0;
}



