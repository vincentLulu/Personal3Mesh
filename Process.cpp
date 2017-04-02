#include "Process.h"

void Method_1_Process::DataProcess() {
	sort(PointInfor.begin(), PointInfor.end());
	//for (int i = 0; i < 3; ++i) {
	//	sort(PointInfor.begin(), PointInfor.end());
	//	for (unordered_map<int, PointData>::iterator iter = PointInfor.begin(); iter != PointInfor.end(); ++iter) {
	//		if (!SearchOperation((*iter).first)) {
	//			(*iter).second.In_or_Out *= -1;
	//		}
	//	}
	//}
}
//
//bool Method_1_Process::SearchOperation(int Vector) {
//	int tempPoint1;
//	int tempPoint2;
//	static int times = 0;
//	switch (times) {
//	case 0:
//		cout << "Origin way search operation: " << endl;
//		tempPoint1 = Vector + 10;
//		tempPoint1 = Vector - 10;
//		if (PointInfor.count(tempPoint1) != 0 && PointInfor.count(tempPoint2) != 0) {
//			return true;
//		}
//		else return false;
//		++times;
//		break;
//	case 1:
//		cout << "Along y-direction search operation" << endl;
//		tempPoint1 = Vector + 100;
//		tempPoint1 = Vector - 100;
//		if (PointInfor.count(tempPoint1) != 0 && PointInfor.count(tempPoint2) != 0) {
//			return true;
//		}
//		else return false;
//		++times;
//		break;
//	case 2:
//		cout << "Along vertical axis search operation" << endl;
//		tempPoint1 = Vector + 1;
//		tempPoint1 = Vector - 1;
//		if (PointInfor.count(tempPoint1) != 0 && PointInfor.count(tempPoint2) != 0) {
//			return true;
//		}
//		else return false;
//		++times;
//		break;
//	}
//
//	
//}

//bool Method_1_Process::sortoperation1(pair <int, PointData> &Fir, pair <int, PointData> &Sec) {
//	string First = to_string(Fir.first);
//	string Second = to_string(Sec.first);
//	return (First[1] < Second[1]);
//	// return (First[1] < Second[1] || (First[1] == Second[1] && First[0] < Second[0]) || (First[1] == Second[1] && First[0] == Second[0] && First[2] < Second[2]));
//}

//bool Method_1_Process::sortoperation2(pair <int, PointData> Fir, pair <int, PointData> Sec) {
//	string First = to_string(Fir.first);
//	string Second = to_string(Sec.first);
//	return (First[0] < Second[0] || (First[0] == Second[0] && First[1] < Second[1]) || (First[0] == Second[0] && First[1] == Second[1] && First[2] < Second[2]));
//}
//
//bool Method_1_Process::sortoperation3(pair <int, PointData> Fir, pair <int, PointData> Sec) {
//	string First = to_string(Fir.first);
//	string Second = to_string(Sec.first);
//	return (First[2] < Second[2] || (First[2] == Second[2] && First[0] < Second[0]) || (First[2] == Second[2] && First[0] == Second[0] && First[1] < Second[1]));
//}

//void Method_1_Process::ReOrder(unordered_map <int, PointData> &PointInfor) {
//	static int times = 0;
//	switch (times) {
//	case 0:
//		cout << "Origin way: " << endl;
//		sort(PointInfor.begin(), PointInfor.end(), sortoperation1);
//		++times;
//		break;
//	case 1:
//		cout << "Along y-direction" << endl;
//		sort(PointInfor.begin(), PointInfor.end(), sortoperation1);
//		++times;
//		break;
//	case 2:
//		cout << "Along vertical axis" << endl;
//		sort(PointInfor.begin(), PointInfor.end(), sortoperation1);
//		++times;
//		break;
//	}
//}


//bool Method_1_Process::Search(Eigen::Vector3d point) {
//	vector<PointData>::iterator iter1, iter2, iter3, iter4;
//	iter1 = find_if(PointInfor.begin(), PointInfor.end(), operation(point[0] + 1, point[1], point[2]));
//	iter2 = find_if(PointInfor.begin(), PointInfor.end(), operation(point[0] - 1, point[1], point[2]));
//	iter3 = find_if(PointInfor.begin(), PointInfor.end(), operation(point[0], point[1] + 1, point[2]));
//	iter4 = find_if(PointInfor.begin(), PointInfor.end(), operation(point[0], point[1] - 1, point[2]));
//	return (iter1 != PointInfor.end() & iter1 != PointInfor.end() & iter1 != PointInfor.end() & iter1 != PointInfor.end());
//}

