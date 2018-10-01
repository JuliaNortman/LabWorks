#pragma once


#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "figures.h"

using namespace std;

class pentagon :public figures
{
public:
	pentagon();
	pentagon(point vert[]);
	~pentagon();
	bool isRight();
	double area();
};

pentagon::pentagon()
{
	n = 5;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		srand(i + time(NULL));
		v[i].x = rand() % 20;
		srand(i + 10 + time(NULL));
		v[i].y = rand() % 20;
	}
	e[0] = length(v[0], v[1]);
	e[1] = length(v[1], v[2]);
	e[2] = length(v[2], v[3]);
	e[3] = length(v[3], v[4]);
	e[4] = length(v[4], v[0]);
}

pentagon::~pentagon()
{
	delete[]e;
	delete[]v;
}

pentagon::pentagon(point vert[])
{
	n = 5;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		v[i] = vert[i];
	}
	e[0] = length(v[0], v[1]);
	e[1] = length(v[1], v[2]);
	e[2] = length(v[2], v[3]);
	e[3] = length(v[3], v[4]);
	e[4] = length(v[4], v[0]);
}

bool pentagon::isRight()
{
	if (isFigure())
	{
		bool equalEdges = e[0] == e[1] && e[1] == e[2] && e[2] == e[3] && e[3] == e[4];
		bool equal1 = abs(scalar(v[4], v[0], v[1], v[0]) / (e[4] * e[0]) - scalar(v[1], v[2], v[3], v[2]) / (e[1] * e[2])) <= eps;
		double equal2 = abs(scalar(v[4], v[0], v[1], v[0]) / (e[4] * e[0]) - scalar(v[2], v[3], v[4], v[3]) / (e[2] * e[3])) <= eps;
		if (equalEdges && equal1 && equal2) return true;
	}
	return false;
}

double pentagon::area()
{
	double l1, l2, p1, p2, p3;
	l1 = length(v[0], v[2]);
	l2 = length(v[2], v[4]);
	p1 = (l1 + e[0] + e[1]) / 2;
	p2 = (l1 + l2 + e[4]) / 2;
	p3 = (l2 + e[2] + e[3]) / 2;
	return sqrt(p1*(p1 - l1)*(p1 - e[0])*(p1 - e[1])) + sqrt(p2*(p2 - l1)*(p2 - l2)*(p2 - e[4])) + sqrt(p3*(p3 - l2)*(p3 - e[2])*(p3 - e[3]));
}