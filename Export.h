#ifndef EXPORT
#define EXPORT
#include "Readin.h"

typedef map<int, Common>::iterator iter;

void Export(map<int, Common> PointCloud2);

void Export_Inner(pair<int, Common> Point, int index);

#endif // !EXPORT
#pragma once
