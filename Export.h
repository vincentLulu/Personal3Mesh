#ifndef EXPORT
#define EXPORT
#include "Readin.h"

typedef map<Eigen::Vector3d, Common>::iterator iter;

void Export(map<Eigen::Vector3d, Common, cmp> PointCloud2);

void Export_Inner(pair<Eigen::Vector3d, Common> Point, int index);

void Export_Outer(pair<Eigen::Vector3d, Common> Point, int index);

#endif // !EXPORT
#pragma once

