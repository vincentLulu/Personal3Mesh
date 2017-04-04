#include "Method2.h"
#include <iostream>

int Count_OutInner(map<Eigen::Vector3d, Common, cmp> PointCloud2) {
	int num = 0;
	for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
		if ((*i).second.Get_In_or_Out() == 0) {
			++num;
		}
	}
	return num;
}


void Identity_OutInner(map<Eigen::Vector3d, Common, cmp>  &PointCloud2) {
	static int times = 1;
	switch (times)
	{
	case 1:
		cout << "times 1: first identify" << endl;
		for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
			Eigen::Vector3d v(0, 0, 1);
			Eigen::Vector3d Front = (*i).first + v;
			Eigen::Vector3d Back = (*i).first - v;
			if (PointCloud2.find(Front) == PointCloud2.end() || PointCloud2.find(Back) == PointCloud2.end()) {
				(*i).second.IdentifyOutInner();
			}
		}
		++times;
		break;
	case 2:
		cout << "times 2: second identify" << endl;
		for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
			Eigen::Vector3d v(0, 1, 0);
			Eigen::Vector3d Front = (*i).first + v;
			Eigen::Vector3d Back = (*i).first - v;
			if (PointCloud2.find(Front) == PointCloud2.end() || PointCloud2.find(Back) == PointCloud2.end()) {
				(*i).second.IdentifyOutInner();
			}
		}
		++times;
		break;
	case 3:
		cout << "times 3: third identify" << endl;
		for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
			Eigen::Vector3d v(1, 0, 0);
			Eigen::Vector3d Front = (*i).first + v;
			Eigen::Vector3d Back = (*i).first - v;
			if (PointCloud2.find(Front) == PointCloud2.end() || PointCloud2.find(Back) == PointCloud2.end()) {
				(*i).second.IdentifyOutInner();
			}
		}
		++times;
		break;
	default:
		break;
	}
}
