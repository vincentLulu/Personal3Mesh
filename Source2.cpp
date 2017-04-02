#include <iostream>
#include <fstream>
#include <Eigen\Dense>
#include "Readin.h"
// #include "Process.h"
#include "Method2.h"

using namespace std;
using namespace Eigen;

int main() {
	Points DataBase;
	const string file("normal-ct-brain");
	string filename;
	for (int i = 0; i < 1; ++i) {
		filename = file + " " + to_string(i) +".jpg";
		DataBase.Readin(filename);
	}
	DataBase.Count();

	Method1 DataBase1;
	string filename1;
	for (int j = 0; j < 1; ++j) {
		filename1 = file + " " + to_string(j) + ".jpg";
		DataBase1.Readin(filename1);
	}
	DataBase1.DataProcess();

	/*Method_1_Process DataBase2;
	for (int i1 = 0; i1 < 1; ++i1) {
		filename = file + " " + to_string(i1) + ".jpg";
		DataBase2.Readin(filename);
	}*/
	// DataBase2.Count();
	//DataBase.DataProcess();
	//DataBase.ReadIn_Out();
 }