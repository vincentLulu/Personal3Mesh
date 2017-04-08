#ifndef EXPORT
#define EXPORT
#include "Readin.h"

typedef map<Eigen::Vector3d, Common>::iterator iter;

void Export(map<Eigen::Vector3d, Common, cmp> PointCloud2);

void Export_Point(pair<Eigen::Vector3d, Common> Point, int index, ofstream &Out);

void Export_Point(pair<Eigen::Vector3d, Common> Point, int index, map<Eigen::Vector3d, Common, cmp> PointCloud2, ofstream &Out);

void Modify(vector <Eigen::Vector3d> &Points, Eigen::Vector3d tempVec, map<Eigen::Vector3d, Common, cmp> PointCloud2);

#endif // !EXPORT
#pragma once
