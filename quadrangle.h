#pragma once
#include "figures.h"



class quadrangle :public figures
{
public:
	quadrangle();
	quadrangle(point vert[]);
	~quadrangle();
	bool isTrapeze();
	bool isParallelogram();
	bool isRhombus();
	bool isRectangle();
	bool isSquare();
	double area();
	void formEdges();
};

void quadrangle::formEdges()
{

	e[0] = length(v[0], v[1]);
	e[1] = length(v[1], v[2]);
	e[2] = length(v[2], v[3]);
	e[3] = length(v[3], v[0]);
}

quadrangle::quadrangle()
{
	n = 4;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		srand(time(NULL) + i);
		v[i].x = rand() % 60;
		srand(time(NULL) + i + 10);
		v[i].y = rand() % 60;
	}
	formEdges();
}

quadrangle::quadrangle(point vert[])
{
	n = 4;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		v[i] = vert[i];
	}
	formEdges();
}

quadrangle::~quadrangle()
{
	delete[]e;
	delete[]v;
}

bool quadrangle::isTrapeze()
{
	if (TriangleInequality())
	{
		if (abs(abs(scalar(v[2], v[1], v[3], v[0])) - e[1] * e[3]) <= eps)
		{
			return true;
		}
		else if (abs(abs(scalar(v[0], v[1], v[3], v[2])) - e[0] * e[2]) <= eps)
		{
			return true;
		}
	}
	return false;
}

bool quadrangle::isParallelogram()
{
	if (TriangleInequality())
	{
		double sc1 = scalar(v[2], v[1], v[3], v[0]) - e[1] * e[3];
		double sc2 = scalar(v[0], v[1], v[3], v[2]) - e[0] * e[2];
		if (abs(sc1 <= eps) && abs(sc2 <= eps)) return true;
	}
	return false;
}

bool quadrangle::isRhombus()
{
	if (isParallelogram())
	{
		if (abs(e[0] - e[1]) <= eps) return true;
	}
	return false;
}

bool quadrangle::isRectangle()
{
	if (isParallelogram())
	{
		if (isRightAngle(v[0], v[1], v[2])) return true;
	}
	return false;
}

bool quadrangle::isSquare()
{
	if (isRhombus())
	{
		if (isRightAngle(v[0], v[1], v[2])) return true;
	}
	return false;
}

double quadrangle::area()
{
	if (isSquare() || isRectangle()) return e[0] * e[1];
	double l = length(v[0], v[2]);
	if (isRhombus() || isParallelogram())
	{
		double p = (l + e[0] + e[1]) / 2;
		return 2 * sqrt(p*(p - e[0])*(p - e[1])*(p - l));
	}
	else
	{
		double p1 = (l + e[0] + e[1]) / 2;
		double p2 = (l + e[2] + e[3]) / 2;
		double s1 = sqrt(p1*(p1 - e[0])*(p1 - e[1])*(p1 - l));
		double s2 = sqrt(p2*(p2 - e[2])*(p2 - e[3])*(p2 - l));
		return s1 + s2;
	}
}
