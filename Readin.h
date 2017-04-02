#ifndef  READIN
#define READIN
#include <Eigen\Dense>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;
using namespace Eigen;

struct Points {
	Points();
	~Points();
	void Readin(const string file);
	void Count();
	
protected:
	struct PointData {
		double x_cords;
		double y_cords;
		double z_cords;
		double scale;
		cv::Scalar intensity;
		int In_or_Out;
	};
	map <int, PointData> PointInfor;
	/*struct cmp {
		cmp(const Points &c) :myclass(c) {}
		bool operator()(pair<int, PointData> &F, pair<int, PointData> &S) {
			return (F.second.In_or_Out == S.second.In_or_Out);
		}
		const Points &myclass;
	};*/
	static bool cmp(const pair<int, PointData> &F, const pair<int, PointData> &S) {
		return(F.second.In_or_Out < S.second.In_or_Out);
	}
};
#endif // ! READIN



#pragma once
