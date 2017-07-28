#include<binarize_wolf.h>
#include<textdetection/characteranalysis.h>
#include <utility.h>
//#include<alpr.h>
#include "detector.h"
#include"binarize_wolf.h"
#include "detectorcpu.h"
#include<alpr_impl.h>
#include<alpr.h>
#include "prewarp.h"
#include "result_aggregator.h"
#include <ocr/segmentation/charactersegmenter.h>


#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgcodecs/imgcodecs.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<prewarp.h>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using namespace alpr;
int main(){
	Mat image;
	image=imread( "large-1.jpg", IMREAD_GRAYSCALE);
	PreWarp* prewarp;
	Config* config;
	config = new Config("us","/usr/local/share/tessdata/lus.traineddata");
	prewarp = ALPR_NULL_PTR;
	prewarp = new PreWarp(config);
	if (config->loaded == false)
	{
		return 0;
	}
	std::vector<cv::Rect> regionsOfInterest;
	regionsOfInterest.push_back(cv::Rect(0, 0, image.cols, image.rows));
	Mat grayImg = image;
	if (image.channels() > 2)
		cvtColor( image, grayImg, CV_BGR2GRAY );
	std::vector<cv::Rect> warpedRegionsOfInterest = regionsOfInterest;

	grayImg = prewarp->warpImage(grayImg);
	warpedRegionsOfInterest = prewarp->projectRects(regionsOfInterest, grayImg.cols, grayImg.rows, false);

	//ResultAggregator iter_aggregator(MERGE_COMBINE, 10, config);
	ResultAggregator country_aggregator(MERGE_PICK_BEST, 25, config);


	AlprImpl impl=AlprImpl("us","/usr/local/share/tessdata/lus.traineddata");

	AlprFullDetails iter_results = impl.analyzeSingleCountry(image,image , warpedRegionsOfInterest);
	image=image(iter_results.plateRegions[0].rect);
	Mat output=image;
	NiblackSauvolaWolfJolion (image,output, SAUVOLA,
			12, 12, 0.36);
	namedWindow("Number",CV_WINDOW_NORMAL);
	imshow("Number",image);
	while(waitKey(30)!=27);

	std::vector<cv::Rect> regionsOfInterest1;
	regionsOfInterest1.push_back(cv::Rect(0, 0, image.cols, image.rows));
	PipelineData pipe=PipelineData(image,regionsOfInterest1[0], config);
	CharacterAnalysis charac=CharacterAnalysis(&pipe);
	charac.analyze();
	Mat a=charac.getCharacterMask();
	namedWindow("Number1",CV_WINDOW_NORMAL);
		imshow("Number1",a);
		while(waitKey(30)!=27);

	return 0;
}
