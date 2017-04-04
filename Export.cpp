#include "Export.h"
#include <iostream>
#include <fstream>


void Export(map<int, Common> PointCloud2) {
	int index = 0;
	for (iter i = PointCloud2.begin(); i != PointCloud2.end(); ++i) {
		if ((*i).second.Get_In_or_Out() == 1) {
			Export_Inner(*i, index);
			++index;
		}
	}
}

void Export_Inner(pair<int, Common> Point, int index) {
	ofstream Out("outMethod2.obj", ios_base::app);
	double x = Point.second.Get_X_Cords();
	double y = Point.second.Get_Y_Cords();
	double z = Point.second.Get_Z_Cords();
	double scale = Point.second.Get_Scale();
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
	Out << "f " << 8 * index + 3 << " " << 8 * index + 4 << " " << 8 * index + 8 << " " << 8 * index + 7 << "\n";
	Out << "f " << 8 * index + 2 << " " << 8 * index + 3 << " " << 8 * index + 7 << " " << 8 * index + 6 << "\n";
	Out << "f " << 8 * index + 1 << " " << 8 * index + 4 << " " << 8 * index + 8 << " " << 8 * index + 5 << "\n\n";
	Out.close();
}