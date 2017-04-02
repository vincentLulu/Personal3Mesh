#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Readin.h"

Points::Points() {
}

Points::~Points() {
}

void Points::Readin(string file) {
	double queue;
	if (file.size() > 4) {
		queue = stod(file.substr(file.size() - 5, 2));
	}
	cout << "reading in " << file << endl;
	cv::Mat img = cv::imread(file);
	cv::cvtColor(img, img, CV_RGB2GRAY);
	if (img.empty()) {
		cout << "error in loading picture!" << endl;
		throw invalid_argument("received negative value");
	}
	int row = img.rows;
	int col = img.cols;
	// Eigen::Vector3d tempVector;
	int tempVector;
	PointData tempData;
	cv::Scalar intensity;
	for (int x = 0; x < row; ++x) {
		for (int y = 0; y < col; ++y) {
			intensity = img.at<uchar>(x, y);
			if (intensity.val[0] > 250) {
				tempVector = 100*x+10*y+int(queue);
				tempData.x_cords = double(x);
				tempData.y_cords = double(y);
				tempData.z_cords = double(queue);
				tempData.scale = 1.0;
				tempData.intensity = intensity;
				tempData.In_or_Out = 1;
				PointInfor.insert(pair<int, PointData>(tempVector, tempData));
			}
		}
	}
}

void Points::Count() {
	std::cout << PointInfor.size() << endl;
}