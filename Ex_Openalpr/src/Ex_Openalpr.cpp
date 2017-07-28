#include<iostream>
#include<alpr.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace alpr;
using namespace std;
using namespace cv;
Alpr openalpr("vn2","/usr/local/share/openalpr/runtime_data/ocr/tessdata/lvn2.traineddata");
int main(){
	//	VideoCapture cap("tra3.mp4"); // open the default camera
	//		if (!cap.isOpened()) {
	//			cout << "HI"; // check if we succeeded
	//
	//			return -1;
	//		}
	Mat img;
	//	cap >> img;
	// Optionally specify the top N possible plates to return (with confidences).  Default is 10
	openalpr.setTopN(20);
//	openalpr.setCountry("vn2");

	// Optionally, provide the library with a region for pattern matching.  This improves accuracy by
	// comparing the plate text with the regional pattern.
	//openalpr.setDefaultRegion("md");

	// Make sure the library loaded before continuing.
	// For example, it could fail if the config/runtime_data is not found
	if (openalpr.isLoaded() == false)
	{
		std::cerr << "Error loading OpenALPR" << std::endl;
		return 1;
	}

	// Recognize an image file.  You could alternatively provide the image bytes in-memory.
	alpr::AlprResults results = openalpr.recognize("1.png");

	// Iterate through the results.  There may be multiple plates in an image,
	// and each plate return sthe top N candidates.
	for (int i = 0; i < results.plates.size(); i++)
	{
		alpr::AlprPlateResult plate = results.plates[i];
		std::cout << "plate" << i << ": " << plate.topNPlates.size() << " results" << std::endl;

		for (int k = 0; k < plate.topNPlates.size(); k++)
		{
			alpr::AlprPlate candidate = plate.topNPlates[k];
			std::cout << "    - " << candidate.characters << " confidence: " << candidate.overall_confidence;
			std::cout << "\t pattern_match: " << candidate.matches_template << std::endl;
		}
	}
	return 0;
}
