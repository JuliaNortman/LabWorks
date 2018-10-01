#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;


/*Фігури на площині: трикутники, чотирикутники, п’ятикутники.
Обчислення периметра та площі фігури. Перевірка на спеціальні фігури
– прямокутні, рівнобедрені, рівносторонні трикутники; трапеції,
паралелограми, ромби, прямокутники, квадрати; правильні
п’ятикутники.*/

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

class triangle :public figures
{
public:
	void print()
	{
		for (int i = 0; i < n; ++i)
		{
			cout << "I: " << i << " " << e[i] << endl;
		}
	}
	triangle();
	triangle(point vert[]);
	~triangle();
	bool isRightTriangle(); //прямоугольный
	bool isIsoscelesTriange(); //равнобедренный
	bool isEquilateral(); //равнобедренный
	double area();
};

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
};

class pentagon :public figures
{
public:
	pentagon();
	pentagon(point vert[]);
	~pentagon();
	bool isRight();
	double area();
}; 

inline double figures::length(point a, point b)
{
	return sqrt( pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
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
	return ( (a.x-b.x)*(c.x-d.x) + (a.y - b.y)*(c.y - d.y) );
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
	if (abs( scalar(a, b, c, b) <= eps)) return true;
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

triangle::triangle()
{
	n = 3;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		srand(i+time(NULL));
		v[i].x = rand()%10;
		srand(time(NULL)+i+10);
		v[i].y = rand()%10;
	}
	e[0] = length(v[0], v[1]);
	e[1] = length(v[1], v[2]);
	e[2] = length(v[2], v[0]);
}

triangle::triangle(point vert[])
{
	n = 3;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		v[i] = vert[i];
	}
	e[0] = length(v[0], v[1]);
	e[1] = length(v[1], v[2]);
	e[2] = length(v[2], v[0]);
}

bool triangle::isRightTriangle()
{
	if (isFigure())
	{
		if (isRightAngle(v[0], v[1], v[2])) return true;
		else if (isRightAngle(v[2], v[0], v[1])) return true;
		else if (isRightAngle(v[1], v[2], v[0])) return true;
	}
	return false;
}

bool triangle::isIsoscelesTriange()
{
	if (isFigure())
	{
		if (abs(e[0] - e[1])<=eps || abs(e[0] - e[2]) <= eps || abs(e[1] - e[2]) <= eps) return true;
	}
	return false;
}

bool triangle::isEquilateral()
{
	if (isFigure() && abs(e[0] - e[1])<= eps && abs(e[0] - e[2])<=eps) return true;
	return false;
}

double triangle::area()
{
	double p = perimeter() / 2;
	return sqrt(p*(p - e[0]) * (p - e[1]) * (p - e[2]));
}

triangle::~triangle()
{
	delete[]e;
	delete[]v;
}

quadrangle::quadrangle()
{
	n = 4;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		srand(time(NULL)+i);
		v[i].x = rand()%60;
		srand(time(NULL)+i+10);
		v[i].y = rand()%60;
	}
	e[0] = length(v[0], v[1]);
	e[1] = length(v[1], v[2]);
	e[2] = length(v[2], v[3]);
	e[3] = length(v[3], v[0]);
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
	e[0] = length(v[0], v[1]);
	e[1] = length(v[1], v[2]);
	e[2] = length(v[2], v[3]);
	e[3] = length(v[3], v[0]);
}

quadrangle::~quadrangle()
{
	delete[]e;
	delete[]v;
}

bool quadrangle::isTrapeze()
{
	if (isFigure()) 
	{
		if (abs(abs(scalar(v[2], v[1], v[3], v[0])) - e[1]*e[3]) <= eps)
		{
			return true;
		}
		else if (abs(abs(scalar(v[0], v[1], v[3], v[2])) - e[0]*e[2]) <= eps)
		{
			return true;
		}
	}
	return false;
}

bool quadrangle::isParallelogram()
{
	if (isFigure())
	{
		if (abs(scalar(v[2], v[1], v[3], v[0]) - e[1]*e[3]) <= eps && abs(scalar(v[0], v[1], v[3], v[2]) - e[0]*e[2]) <= eps) return true;
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
		return sqrt(p1*(p1 - e[0])*(p1 - e[1])*(p1 - l)) + sqrt(p2*(p2 - e[2])*(p2 - e[3])*(p2 - l));
	}
}

pentagon::pentagon()
{
	n = 5;
	e = new double[n];
	v = new point[n];
	for (int i = 0; i < n; ++i)
	{
		srand(i + time(NULL));
		v[i].x = rand()%20;
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
		bool equal1 = abs(scalar(v[4], v[0], v[1], v[0])/(e[4] * e[0]) - scalar(v[1], v[2], v[3], v[2])/(e[1] * e[2])) <= eps;
		double equal2 = abs(scalar(v[4], v[0], v[1], v[0])/(e[4] * e[0]) - scalar(v[2], v[3], v[4], v[3])/(e[2] * e[3])) <= eps;
		if (equalEdges && equal1 && equal2) return true;
	}
	return false;
}

double pentagon::area()
{
	double l1, l2, p1, p2, p3;
	l1 = length(v[0], v[2]);
	l2 = length(v[2], v[4]);
	p1 = (l1 + e[0] + e[1])/2;
	p2 = (l1 + l2 + e[4]) / 2;
	p3 = (l2 + e[2] + e[3]) / 2;
	return sqrt(p1*(p1 - l1)*(p1-e[0])*(p1-e[1])) + sqrt(p2*(p2 - l1)*(p2 - l2)*(p2 - e[4])) + sqrt(p3*(p3 - l2)*(p3 - e[2])*(p3 - e[3]));
}

int main()
{
	point tr[3] = { {2,1}, {2,5}, {5,1} };
	triangle t;
	cout << "Triangle" << endl;
	t.print();
	cout << "Is Triangle: " << t.isFigure() << endl;
	cout << "Is right triangle: " << t.isRightTriangle() << endl;
	cout << "Is isoscenceles Triangle: " << t.isIsoscelesTriange() << endl;
	cout << "Is equilateral triangle: " << t.isEquilateral() << endl;
	cout << "Perimeter: " << t.perimeter() << endl;
	cout << "Area: " << t.area() << endl << endl;

	point qua[] = { {2,6}, {4,8}, {8,4},  {2, 6} };
	quadrangle q;
	cout << "Quadrangle" << endl;
	q.print();
	cout << "Is trapeze: " << q.isTrapeze() << endl;
	cout << "Is parallelogram: " <<  q.isParallelogram() << endl;
	cout << "Is rhombus: " << q.isRhombus() << endl;
	cout << "Is rectangular: " << q.isRectangle() << endl;
	cout << "Is square: " <<q.isSquare() << endl;
	cout << "Perimeter: " << q.perimeter() << endl;
	cout << "Area: " << q.area() << endl << endl;
	

	pentagon p;
	cout << "Pentagon" << endl;
	p.print();
	cout << "Is right: " << p.isRight() << endl;
	cout << "Perimeter: " << p.perimeter() << endl;
	cout << "Area: " << p.area() << endl;
	system("pause");
	return 0;
}