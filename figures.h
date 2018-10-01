#pragma once
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

/*
#include "figures.h"
#include "triangle.h"
#include "quadrangle.h"
#include "pentagon.h"*/

using namespace std;

struct point
{
	int x, y;
};

class figures
{
protected:
	int n; //number of vertexes
	point *v; // coordinates of vertexes
	double *e; //length of edges
	const double eps = 0.01;
public:
	double length(point a, point b);
	bool isFigure();
	double perimeter();
	bool isRightAngle(point a, point b, point c);
	void setZero();
	double scalar(point a, point b, point c, point d);
	void print();
};


inline double figures::length(point a, point b)
{
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

bool figures::isFigure()
{
	double length = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j) length += e[j];
		for (int j = i + 1; j < n; ++j)
		{
			length += e[j];
			if (v[i].x == v[j].x && v[i].y == v[j].y)
			{
				setZero();
				return false;
			}
		}
		if (length <= e[i])
		{
			setZero();
			return false;
		}
	}
	return true;
}
double figures::scalar(point a, point b, point c, point d)
{
	return ((a.x - b.x)*(c.x - d.x) + (a.y - b.y)*(c.y - d.y));
}


void figures::setZero()
{
	for (int i = 0; i < n; ++i)
	{
		e[i] = 0;
		v[i].x = v[i].y = 0;
	}
}

double figures::perimeter()
{
	double p = 0;
	for (int i = 0; i < n; ++i)
	{
		p += e[i];
	}
	return p;
}

inline bool figures::isRightAngle(point a, point b, point c)
{
	if (abs(scalar(a, b, c, b) <= eps)) return true;
	return false;
}

void figures::print()
{
	for (int i = 0; i < n; ++i)
	{
		cout << "X: " << v[i].x << " Y: " << v[i].y << endl;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << "E: " << e[i] << endl;
	}
}