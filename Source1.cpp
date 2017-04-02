#include <string>
#include <iostream>
#include <fstream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include <Eigen\Dense>

using namespace cv;
using namespace std;

int main() {
	ofstream out3("out3.obj");
	string file("normal-ct-brain (");
	double scale = 2;
	double x_cor;
	double y_cor;
	double z_cor;
	int flag = 1;
	Scalar intensity;
	for (int i = 0; i < 7; ++i) {
		cout << file << i << endl;
		Mat img = imread(file + to_string(i) + ").jpg");
		if (img.empty()) {
			cout << "error in loading file" << endl;
			return -1;
		}
	//	/*namedWindow("haha");
	//	imshow("haha", img);
	//	waitKey(6000);
	//	destroyWindow("haha");*/
		cvtColor(img, img, CV_RGB2GRAY);
		const int row = img.rows;
		const int col = img.cols;
		for (int x = 0; x < row; ++x) {
			for (int y = 0; y < col; ++y) {
				intensity = img.at<uchar>(x, y);
				if (intensity.val[0] > 250) {
					x_cor = double(x);
					y_cor = double(y);
					out3 << "v " << (x_cor - 0.5)*scale << " " << (y_cor - 0.5)*scale << " " << (double(i) - 0.5)*5 << "\n";
					out3 << "v " << (x_cor - 0.5)*scale << " " << (y_cor + 0.5)*scale << " " << (double(i) - 0.5)*5 << "\n";
					out3 << "v " << (x_cor + 0.5)*scale << " " << (y_cor + 0.5)*scale << " " << (double(i) - 0.5)*5 << "\n";
					out3 << "v " << (x_cor + 0.5)*scale << " " << (y_cor - 0.5)*scale << " " << (double(i) - 0.5)*5 << "\n";

					out3 << "v " << (x_cor - 0.5)*scale << " " << (y_cor - 0.5)*scale << " " << (double(i) + 0.5)*5 << "\n";
					out3 << "v " << (x_cor - 0.5)*scale << " " << (y_cor + 0.5)*scale << " " << (double(i) + 0.5)*5 << "\n";
					out3 << "v " << (x_cor + 0.5)*scale << " " << (y_cor + 0.5)*scale << " " << (double(i) + 0.5)*5 << "\n";
					out3 << "v " << (x_cor + 0.5)*scale << " " << (y_cor - 0.5)*scale << " " << (double(i) + 0.5)*5 << "\n";

					out3 << "f " << flag << " " << flag + 1 << " " << flag + 2 << " " << flag + 3 << "\n";
					out3 << "f " << flag + 4 << " " << flag + 5 << " " << flag + 6 << " " << flag + 7 << "\n";
					out3 << "f " << flag << " " << flag + 1 << " " << flag + 5 << " " << flag + 4 << "\n";
					out3 << "f " << flag + 3 << " " << flag + 2 << " " << flag + 6 << " " << flag + 7 << "\n";
					out3 << "f " << flag + 1 << " " << flag + 5 << " " << flag + 6 << " " << flag + 2 << "\n";
					out3 << "f " << flag  << " " << flag + 4 << " " << flag + 7 << " " << flag + 3 << "\n";

					flag += 8;
				}
			}
		}
	}
	out3.close();
	return 0;	
}