#ifndef  READIN
#define READIN
#include <Eigen\Dense>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <map>

using namespace std;
using namespace Eigen;

struct Common {
	Common();
	~Common();
	void Readin(const string file, map<int, Common> &target);
	double Get_X_Cords();
	double Get_Y_Cords();
	double Get_Z_Cords();
	double Get_Scale();
	cv::Scalar Get_CVScalar();
	int Get_In_or_Out();
	void IdentifyOutInner() {
		Assign_In_or_Out(0);
	}
protected:
	void Assign_X_cords(double value);
	void Assign_Y_cords(double value);
	void Assign_Z_cords(double value);
	void Assign_scale(double value);
	void Assign_CVScalar(cv::Scalar value);
	void Assign_In_or_Out(int value);

	double x_cords;
	double y_cords;
	double z_cords;
	double scale;
	cv::Scalar intensity;
	int In_or_out;
};
#endif // ! READIN



#pragma once
