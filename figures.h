#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <ctime>


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
	friend double length(point a, point b);
	bool TriangleInequality();
	double perimeter();
	bool isRightAngle(point a, point b, point c);
	void setZero();
	friend double scalar(point a, point b, point c, point d);
	void print();
};


inline double length(point a, point b)
{
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

bool figures::TriangleInequality()
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
double scalar(point a, point b, point c, point d)
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
		std::cout << "X: " << v[i].x << " Y: " << v[i].y << std::endl;
	}
	for (int i = 0; i < n; ++i)
	{
		std::cout << "E: " << e[i] << std::endl;
	}
}