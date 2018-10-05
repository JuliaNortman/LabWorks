#include "figures.h"
#include "pentagon.h"
#include "quadrangle.h"
#include "triangle.h"
#include "ArrGraph.h"
#include "ListGraph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <ctime>



/*Графи на основі списку суміжності, матриці суміжності. Перевірка на
зв’язність графу. Визначення відстані між двома вершинами графу.*/



int main()
{
	setlocale(LC_ALL, "Russian");
	int d1[] = { 10, 20, 30, 40, 50 };
	double d2[] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
	std::string d3[] = { "apple", "lemon", "grape", "pineapple", "banana" };


	ArrGraph<int> g1("File1.bin", d1);
	ArrGraph<double> g2("File2.bin", d2);
	ArrGraph<std::string> g3("File3.bin", d3);

	g1.print();
	bool connect = g1.connected();
	if (connect) std::cout << "Graph is connected" << std::endl;
	else std::cout << "Graph is not connected" << std::endl;
	int l1 = g1.arrDistance(1, 3);
	std::cout << "Distance is : " << l1 << std::endl;
	std::cout << std::endl << "******" << std::endl;

	
	g2.print();
	connect = g2.connected();
	if (connect) std::cout << "Graph is connected" << std::endl;
	else std::cout << "Graph is not connected" << std::endl;
	int l2 = g2.arrDistance(0, 4);
	std::cout << "Distance is : " << l2 << std::endl;
	std::cout << std::endl << "******" << std::endl;

	
	g3.print();
	connect = g3.connected();
	if (connect) std::cout << "Graph is connected" << std::endl;
	else std::cout << "Graph is not connected" << std::endl;
	int l3 = g3.arrDistance(0, 1);
	std::cout << "Distance is : " << l3 << std::endl;
	std::cout << std::endl << "******" << std::endl;


	point tr[3] = { { 2,1 },{ 2,5 },{ 5,1 } };
	triangle t;
	std::cout << "Triangle" << std::endl;
	t.print();
	std::cout << "Is Triangle: " << t.TriangleInequality() << std::endl;
	std::cout << "Is right triangle: " << t.isRightTriangle() << std::endl;
	std::cout << "Is isoscenceles Triangle: " << t.isIsoscelesTriange() << std::endl;
	std::cout << "Is equilateral triangle: " << t.isEquilateral() << std::endl;
	std::cout << "Perimeter: " << t.perimeter() << std::endl;
	std::cout << "Area: " << t.area() << std::endl << std::endl;

	point qua[] = { { 2,6 },{ 4,8 },{ 8,4 },{ 2, 6 } };
	quadrangle q;
	std::cout << "Quadrangle" << std::endl;
	q.print();
	std::cout << "Is trapeze: " << q.isTrapeze() << std::endl;
	std::cout << "Is parallelogram: " << q.isParallelogram() << std::endl;
	std::cout << "Is rhombus: " << q.isRhombus() << std::endl;
	std::cout << "Is rectangular: " << q.isRectangle() << std::endl;
	std::cout << "Is square: " << q.isSquare() << std::endl;
	std::cout << "Perimeter: " << q.perimeter() << std::endl;
	std::cout << "Area: " << q.area() << std::endl << std::endl;


	pentagon p;
	std::cout << "Pentagon" << std::endl;
	p.print();
	std::cout << "Is right: " << p.isRight() << std::endl;
	std::cout << "Perimeter: " << p.perimeter() << std::endl;
	std::cout << "Area: " << p.area() << std::endl;

	system("pause");
	return 0;
}
