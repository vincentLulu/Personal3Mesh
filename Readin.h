#ifndef  READIN
#define READIN
#include <Eigen\Dense>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <map>

using namespace std;
using namespace Eigen;

struct cmp {
	bool operator()(const Eigen::Vector3d first, const Eigen::Vector3d second) const {
		return (first[0] > second[0] ||
			(first[0] == second[0] && first[1] > second[1]) ||
			(first[0] == second[0] && first[1] == second[1] && first[2] > second[2]));
	}
};

struct Common {
	Common();
	~Common();
	void Readin(const string file, map<Eigen::Vector3d, Common, cmp> &target);
	double Get_X_Cords();
	double Get_Y_Cords();
	double Get_Z_Cords();
	double Get_Scale();
	cv::Scalar Get_CVScalar();
	int Get_In_or_Out();
	Eigen::Vector3d Get_Normal();
	void IdentifyOutInner() {
		Assign_In_or_Out(0);
	}
	void IdentifyNormal(Eigen::Vector3d vector) {
		Modify_Normal(vector);
	}
	
protected:
	void Assign_X_cords(double value);
	void Assign_Y_cords(double value);
	void Assign_Z_cords(double value);
	void Assign_scale(double value);
	void Assign_CVScalar(cv::Scalar value);
	void Assign_In_or_Out(int value);
	void Assign_Normal();
	void Modify_Normal(Eigen::Vector3d value);

	double x_cords;
	double y_cords;
	double z_cords;
	double scale;
	Eigen::Vector3d normal;
	cv::Scalar intensity;
	int In_or_out;
};
