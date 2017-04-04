#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Readin.h"

Common::Common() {
}

Common::~Common() {
}

void Common::Readin(string file, map<Eigen::Vector3d, Common, cmp> &target) {
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
	cv::namedWindow("hah");
	cv::imshow("hah", img);
	cv::waitKey(600);
	cv::destroyWindow("hah");

	/*ofstream Out("testetsetsetset.obj");
	int flag = 1;*/

	Eigen::Vector3d tempVector;
	int row = img.rows;
	int col = img.cols;
	Common tempCommon;
	cv::Scalar intensity;
	for (int x = 0; x < row; ++x) {
		for (int y = 0; y < col; ++y) {
			intensity = img.at<uchar>(x, y);
			if (intensity.val[0] > 250) {
				tempVector << double(x), double(y), queue;
				tempCommon.Assign_X_cords(double(x));
				tempCommon.Assign_Y_cords(double(y));
				tempCommon.Assign_Z_cords(double(queue));
				tempCommon.Assign_scale(1);
				tempCommon.Assign_CVScalar(intensity);
				tempCommon.Assign_In_or_Out(1);
				
				target.insert(pair<Eigen::Vector3d, Common>(tempVector, tempCommon));

				/*Out << "v " << (x - 0.5) << " " << (y - 0.5) << " " << (queue - 0.5) << "\n";
				Out << "v " << (x - 0.5) << " " << (y + 0.5) << " " << (queue - 0.5) << "\n";
				Out << "v " << (x + 0.5) << " " << (y + 0.5) << " " << (queue - 0.5) << "\n";
				Out << "v " << (x + 0.5) << " " << (y - 0.5) << " " << (queue - 0.5) << "\n";
				Out << "v " << (x - 0.5) << " " << (y - 0.5) << " " << (queue + 0.5) << "\n";
				Out << "v " << (x - 0.5) << " " << (y + 0.5) << " " << (queue + 0.5) << "\n";
				Out << "v " << (x + 0.5) << " " << (y + 0.5) << " " << (queue + 0.5) << "\n";
				Out << "v " << (x + 0.5) << " " << (y - 0.5) << " " << (queue + 0.5) << "\n";
				Out << "f " << flag << " " << flag + 1 << " " << flag + 2 << " " << flag + 3 << "\n";
				Out << "f " << flag + 4 << " " << flag + 5 << " " << flag + 6 << " " << flag + 7 << "\n";
				Out << "f " << flag << " " << flag + 1 << " " << flag + 5 << " " << flag + 4 << "\n";
				Out << "f " << flag + 3 << " " << flag + 2 << " " << flag + 6 << " " << flag + 7 << "\n";
				Out << "f " << flag + 1 << " " << flag + 5 << " " << flag + 6 << " " << flag + 2 << "\n";
				Out << "f " << flag  << " " << flag + 4 << " " << flag + 7 << " " << flag + 3 << "\n";
				Out << flag << " " << tempVector[0] << "\n";
				flag = flag + 1;*/
			}
		}
	}
}


double Common::Get_X_Cords() {
	return x_cords;
}
double Common::Get_Y_Cords() {
	return y_cords;
}
double Common::Get_Z_Cords() {
	return z_cords;
}
double Common::Get_Scale() {
	return scale;
}

cv::Scalar Common::Get_CVScalar() {
	return intensity;
}
int Common::Get_In_or_Out() {
	return In_or_out;
}

void Common::Assign_X_cords(double value) {
	x_cords = value;
}
void Common::Assign_Y_cords(double value) {
	y_cords = value;
}
void Common::Assign_Z_cords(double value) {
	z_cords = value;
}
void Common::Assign_scale(double value) {
	scale = value;
}
void  Common::Assign_CVScalar(cv::Scalar value) {
	intensity = value;
}
void Common::Assign_In_or_Out(int value) {
	In_or_out = value;
}
