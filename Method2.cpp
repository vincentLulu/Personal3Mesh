#include "Method2.h"
#include <iostream>

int Count_OutInner(map<int, Common> PointCloud2) {
	int num = 0;
	for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
		if ((*i).second.Get_In_or_Out() == 0) {
			++num;
		}
	}
	return num;
}


void Identity_OutInner(map<int, Common>  &PointCloud2) {
	static int times = 1;
	switch (times)
	{
	case 1:
		cout << "times 1: first identify" << endl;
		for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
			int Front = (*i).first + 1;
			int Back = (*i).first - 1;
			if (PointCloud2.count(Front) == 0 || PointCloud2.count(Back) == 0) {
				(*i).second.IdentifyOutInner();
			}
		}
		++times;
		break;
	case 2:
		cout << "times 2: second identify" << endl;
		for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
			int Front = (*i).first + 10;
			int Back = (*i).first - 10;
			if (PointCloud2.count(Front) == 0 || PointCloud2.count(Back) == 0) {
				(*i).second.IdentifyOutInner();
			}
		}
		++times;
		break;
	case 3:
		cout << "times 3: third identify" << endl;
		for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
			int Front = (*i).first + 100;
			int Back = (*i).first - 100;
			if (PointCloud2.count(Front) == 0 || PointCloud2.count(Back) == 0) {
				(*i).second.IdentifyOutInner();
			}
		}
		++times;
		break;
	default:
		break;
	}
}