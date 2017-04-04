#include <iostream>
#include <fstream>
#include <Eigen\Dense>
#include "Readin.h"
#include "Method2.h"
#include "Export.h"

using namespace std;
using namespace Eigen;

int main() {
	/***** Common functions tests *****/
	Common DataBase;
	map<int, Common> PointCloud;
	const string file("normal-ct-brain");
	string filename;
	for (int i = 0; i < 1; ++i) {
		filename = file + " " + to_string(i) +".jpg";
		DataBase.Readin(filename, PointCloud);
	}
	cout << "Total Nodes: " << PointCloud.size() << endl;

	/***** Method 1 *****/
	Common DataBase1;
	map<int, Common> PointCloud1;
	string filename1;
	for (int i1 = 0; i1 < 4; ++i1) {
		filename1 = file + " " + to_string(i1) + ".jpg";
		DataBase1.Readin(filename1, PointCloud1);
	}
	cout << "Total Nodes: " << PointCloud1.size() << endl;

	//// Procedure of Export
	Export(PointCloud);


	/***** Method 2 which identify the surface element and innner elements *****/
	Common DataBase2;
	map<int, Common> PointCloud2;
	string filename2;
	for (int i = 0; i < 4; ++i) {
		filename2 = file + " " + to_string(i) + ".jpg";
		DataBase2.Readin(filename2, PointCloud2);
	}
	cout << "Total Nodes: " << PointCloud2.size() << endl;
	
	// Procedure of Identify
	cout <<"before identify, No. of surface nodes: " << Count_OutInner(PointCloud2) << endl;
	for (int i = 0; i < 3; ++i) {
		Identity_OutInner(PointCloud2);
	}
	cout << "after identify, No. of surface nodes: " << Count_OutInner(PointCloud2) << endl;

	// Procedure of Export
	Export(PointCloud2);
 }