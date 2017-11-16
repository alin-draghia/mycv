// obj.train.detect.cpp : Defines the entry point for the console application.
//

#include <memory>
#include <opencv2/opencv.hpp>
#include "../mycv/mycv.hpp"


int main(int argc, char* argv[])
{

	using namespace mycv;
	using namespace std;

	auto tmpl_img = mycv::ImgT( cv::imread("sample/1.jpg", CV_LOAD_IMAGE_GRAYSCALE) , true);
	auto test_img = mycv::ImgT( cv::imread("sample/7.jpg", CV_LOAD_IMAGE_GRAYSCALE) , true);

	auto tmpl_bb = mycv::BB( 122.0f, 53.0f, 53.0f, 58.0f );

	
	cv::rectangle(tmpl_img.img, tmpl_bb, cv::Scalar::all(255.0));
	cv::imshow("dbg", tmpl_img.img);
	

	auto featuresExtractor	= make_shared<mycv::HaarFeaturesExtractor>(5, 10);
	auto classifier			= make_shared<ForestClassifier<mycv::FernClassifier> >(10, 5);
	auto scanner			= make_shared<Scanner>(Size(24, 24), Size(320, 240), 0.25, 1.2);
	auto detector			= Detector<ForestClassifier<mycv::FernClassifier> , mycv::HaarFeaturesExtractor>(scanner, classifier, featuresExtractor);

	detector.learn(tmpl_img, tmpl_bb, true);
	
	vector<BB> objs;
	vector<float> probs;

	detector.detect(test_img, objs, probs);

	for_each(begin(objs), end(objs), [&test_img](BBRefC obj) {
		cv::rectangle(test_img.img, obj, cv::Scalar::all(255));
	});

	cv::imshow("result", test_img.img);
	cv::waitKey();
	

	return 0;
}

