#ifndef PROCESS
#define PROCESS
#include <vector>
#include <iostream>
#include <algorithm>
#include "Readin.h"

struct Method_1_Process:public Points {
	using Points::Readin;
	using Points::Count;
	void DataProcess();
	/*void ReadIn_Out() {
		int i = 0;
		for (unordered_map<int, PointData>::iterator iter = PointInfor.begin(); iter != PointInfor.end(); ++iter) {
			if ((*iter).second.In_or_Out == 1) {
				++i;
			}
		}
		cout << "there are " << i << "inside node"<< endl;
	}*/
private:
	//bool sortoperation1(pair <int, PointData> &first, pair <int, PointData> &second);
	//static bool sortoperation2(pair <int, PointData> first, pair <int, PointData> second);
	//static bool sortoperation3(pair <int, PointData> first, pair <int, PointData> second);
	// void ReOrder(unordered_map <int, PointData> &PointInfor);
	//bool SearchOperation(int Vector);
	int InNumber;

	/*struct operation {
		operation(double x_cord, double y_cord, double z_cord) : x(x_cord), y(y_cord), z(z_cord) {}
		bool operator()(const PointData & P) const {
			return (P.Coords[0] == x & P.Coords[1] == y & P.Coords[2] == z);
		}
	private:
		double x;
		double y;
		double z;
	};
	bool Search(Eigen::Vector3d point) {
		vector<PointData>::iterator iter1, iter2, iter3, iter4;
		iter1 = find_if(PointInfor.begin(), PointInfor.end(), operation(point[0] + 1, point[1], point[2]));
		iter2 = find_if(PointInfor.begin(), PointInfor.end(), operation(point[0] - 1, point[1], point[2]));
		iter3 = find_if(PointInfor.begin(), PointInfor.end(), operation(point[0], point[1] + 1, point[2]));
		iter4 = find_if(PointInfor.begin(), PointInfor.end(), operation(point[0], point[1] - 1, point[2]));
		return (iter1 != PointInfor.end() & iter1 != PointInfor.end() & iter1 != PointInfor.end() & iter1 != PointInfor.end());
	}*/
};

#endif // !PROCESS
#pragma once
