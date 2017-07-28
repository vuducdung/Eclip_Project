#include<binarize_wolf.h>
#include<textdetection/characteranalysis.h>
#include <utility.h>
//#include<alpr.h>
#include "detector.h"
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

	std::vector<cv::Rect> regionsOfInterest;
	regionsOfInterest.push_back(cv::Rect(0, 0, image.cols, image.rows));

	AlprImpl impl=AlprImpl("us","/usr/local/share/tessdata/lus.traineddata");//su dung mo hinh train us
	impl.setTopN(20);//chon so n trong danh sach cac ung cu vien
	AlprFullDetails response= impl.recognizeFullDetails(image,regionsOfInterest);
	alpr::AlprResults results =response.results;//chua 1 tap cac  bien so


	//impl.setDefaultRegion("md");

	for (unsigned i = 0; i < results.plates.size(); i++)
	{
		alpr::AlprPlateResult plate = results.plates[i];//bien so chua danh sach cac ung cu vien
		std::cout << "plate" << i << ": " << plate.topNPlates.size() << " results" << std::endl;

		for (unsigned k = 0; k < plate.topNPlates.size(); k++)
		{
			alpr::AlprPlate candidate = plate.topNPlates[k];//moi ung cu vien chua cac ki tu cua bien so va do tin cay
			std::cout << "    - " << candidate.characters << "\t confidence: " << candidate.overall_confidence;
			std::cout << "\t pattern_match: " << candidate.matches_template << std::endl;
		}
	}

	return 0;
}
