#include "Export.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

inline bool exist_check(const string &file) {
	struct stat buffer;
	return (stat(file.c_str(), &buffer) == 0);
}


void Export(map<Eigen::Vector3d, Common, cmp> PointCloud2) {
	string filename("outMethod2.obj");
	if (exist_check(filename)) {
		remove(filename.c_str());
	}
	ofstream Out(filename);
	int index = 0;
	for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
		if ((*i).second.Get_In_or_Out() == 1) {
			Export_Point(*i, index, Out);
			++index;
		}
		else {

			Export_Point(*i, index, PointCloud2, Out);
			++index;
		}
	}
	cout << "index:" << index << endl;
	Out.close();
}

void Export_Point(pair<Eigen::Vector3d, Common> Point, int index, ofstream &Out) {
	double x = Point.second.Get_X_Cords();
	double y = Point.second.Get_Y_Cords();
	double z = Point.second.Get_Z_Cords();
	double scale = Point.second.Get_Scale();
	// Out << index << "\n";
	Out << "v " << scale*(x - 0.5) << " " << scale*(y - 0.5) << " " << scale*(z - 0.5) << "\n";
	Out << "v " << scale*(x - 0.5) << " " << scale*(y + 0.5) << " " << scale*(z - 0.5) << "\n";
	Out << "v " << scale*(x + 0.5) << " " << scale*(y + 0.5) << " " << scale*(z - 0.5) << "\n";
	Out << "v " << scale*(x + 0.5) << " " << scale*(y - 0.5) << " " << scale*(z - 0.5) << "\n";
	Out << "v " << scale*(x - 0.5) << " " << scale*(y - 0.5) << " " << scale*(z + 0.5) << "\n";
	Out << "v " << scale*(x - 0.5) << " " << scale*(y + 0.5) << " " << scale*(z + 0.5) << "\n";
	Out << "v " << scale*(x + 0.5) << " " << scale*(y + 0.5) << " " << scale*(z + 0.5) << "\n";
	Out << "v " << scale*(x + 0.5) << " " << scale*(y - 0.5) << " " << scale*(z + 0.5) << "\n";
	Out << "f " << 8 * index + 1 << " " << 8 * index + 2 << " " << 8 * index + 3 << " " << 8 * index + 4 << "\n";
	Out << "f " << 8 * index + 5 << " " << 8 * index + 6 << " " << 8 * index + 7 << " " << 8 * index + 8 << "\n";
	Out << "f " << 8 * index + 1 << " " << 8 * index + 2 << " " << 8 * index + 6 << " " << 8 * index + 5 << "\n";
	Out << "f " << 8 * index + 4 << " " << 8 * index + 3 << " " << 8 * index + 7 << " " << 8 * index + 8 << "\n";
	Out << "f " << 8 * index + 2 << " " << 8 * index + 6 << " " << 8 * index + 7 << " " << 8 * index + 3 << "\n";
	Out << "f " << 8 * index + 1 << " " << 8 * index + 5 << " " << 8 * index + 8 << " " << 8 * index + 4 << "\n";
}

void Export_Point(pair<Eigen::Vector3d, Common> Point, int index, map<Eigen::Vector3d, Common, cmp> PointCloud2, ofstream &Out) {
	double x = Point.second.Get_X_Cords();
	double y = Point.second.Get_Y_Cords();
	double z = Point.second.Get_Z_Cords();
	//double scale = Point.second.Get_Scale();
	//// Out << index << "\n";
	//Out << "v " << scale*(x - 0.5) << " " << scale*(y - 0.5) << " " << scale*(z - 0.5) << "\n";
	//Out << "v " << scale*(x - 0.5) << " " << scale*(y + 0.5) << " " << scale*(z - 0.5) << "\n";
	//Out << "v " << scale*(x + 0.5) << " " << scale*(y + 0.5) << " " << scale*(z - 0.5) << "\n";
	//Out << "v " << scale*(x + 0.5) << " " << scale*(y - 0.5) << " " << scale*(z - 0.5) << "\n";
	//Out << "v " << scale*(x - 0.5) << " " << scale*(y - 0.5) << " " << scale*(z + 0.5) << "\n";
	//Out << "v " << scale*(x - 0.5) << " " << scale*(y + 0.5) << " " << scale*(z + 0.5) << "\n";
	//Out << "v " << scale*(x + 0.5) << " " << scale*(y + 0.5) << " " << scale*(z + 0.5) << "\n";
	//Out << "v " << scale*(x + 0.5) << " " << scale*(y - 0.5) << " " << scale*(z + 0.5) << "\n";
	//Out << "f " << 8 * index + 1 << " " << 8 * index + 2 << " " << 8 * index + 3 << " " << 8 * index + 4 << "\n";
	//Out << "f " << 8 * index + 5 << " " << 8 * index + 6 << " " << 8 * index + 7 << " " << 8 * index + 8 << "\n";
	//Out << "f " << 8 * index + 1 << " " << 8 * index + 2 << " " << 8 * index + 6 << " " << 8 * index + 5 << "\n";
	//Out << "f " << 8 * index + 4 << " " << 8 * index + 3 << " " << 8 * index + 7 << " " << 8 * index + 8 << "\n";
	//Out << "f " << 8 * index + 2 << " " << 8 * index + 6 << " " << 8 * index + 7 << " " << 8 * index + 3 << "\n";
	//Out << "f " << 8 * index + 1 << " " << 8 * index + 5 << " " << 8 * index + 8 << " " << 8 * index + 4 << "\n";
	
	Eigen::Vector3d normal = Point.second.Get_Normal();
	Eigen::Matrix3d tempMat;
	tempMat.setIdentity();
	for (int i = 0; i < 3; ++i) {
		if (normal[i] != 0) {
			tempMat(i, i) = pow(0.5, normal[i]);
		}
	}
	
	vector <Eigen::Vector3d> Points;
	Eigen::Vector3d Point001(0, 0, 1);
	Eigen::Vector3d Point011(0, 1, 1);
	Eigen::Vector3d Point111(1, 1, 1);
	Eigen::Vector3d Point101(1, 0, 1);
	Eigen::Vector3d Point000(0, 0, 0);
	Eigen::Vector3d Point010(0, 1, 0);
	Eigen::Vector3d Point110(1, 1, 0);
	Eigen::Vector3d Point100(1, 0, 0);
	Points.push_back(Point001);
	Points.push_back(Point011);
	Points.push_back(Point111);
	Points.push_back(Point101);
	Points.push_back(Point000);
	Points.push_back(Point010);
	Points.push_back(Point110);
	Points.push_back(Point100);

	Eigen::Vector3d tempVec;
	tempVec = Point.first + Eigen::Vector3d(-1, -1, 1);
	Modify(Points, tempVec, PointCloud2);

	tempVec = Point.first + Eigen::Vector3d(-1, 1, 1);
	Modify(Points, tempVec, PointCloud2);


	tempVec = Point.first + Eigen::Vector3d(1, -1, 1);
	Modify(Points, tempVec, PointCloud2);

	tempVec = Point.first + Eigen::Vector3d(1, 1, 1);
	Modify(Points, tempVec, PointCloud2);

	for (vector <Eigen::Vector3d>::iterator i = Points.begin(); i != Points.end(); ++i) {
		if (find(Points.begin(), i, (*i)) != i) {
			Out << "f " << (*i)[0] + x << " " << (*i)[1] + y << " " << (*i)[2] + z << "\n";
		}
	}
}

void Modify(vector <Eigen::Vector3d> &Points, Eigen::Vector3d tempVec, map<Eigen::Vector3d, Common, cmp> PointCloud2) {
	static int index = 0;
	int content[3]; // 0: empty; 1: solid element; 2: surface element.
	for (int i = 0; i < 3; i++) {
		if (PointCloud2.find(tempVec) == PointCloud2.end()) {
			content[i] = 0;
		}
		else {
			if (PointCloud2.at(tempVec).Get_In_or_Out() == 1) {
				content[i] = 1;
			}
			else
				content[i] = 2;
		}
		tempVec += Eigen::Vector3d(0, 0, -1);
	}

	if (content[1] == 2) {
		// surface -> shrink edge to half
		if (content[0] == 0) {
			Points[index+4] += Eigen::Vector3d(0, 0 - 0.5);
		}
		else
			Points[index+4] += Eigen::Vector3d(0, 0, 0.5);
	}
	else if (content[1] == 0) {
		// empty on side -> shrink to bottom
		if (content[0] == 0) {
			Points[index] += Eigen::Vector3d(0, 0, -1);
		}
		else
			Points[index] += Eigen::Vector3d(0, 0, 1);
	}
	else {
		// solid on side -> no change;
	}
	++index;
}
