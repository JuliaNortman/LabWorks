#include <iostream>
#include <fstream>
#include <string>
#include "stack"
#include "Graph.h"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "figures.h"
#include "pentagon.h"
#include "quadrangle.h"
#include "triangle.h"


using namespace std;

/*Графи на основі списку суміжності, матриці суміжності. Перевірка на
зв’язність графу. Визначення відстані між двома вершинами графу.*/



int main()
{

	int d1[] = { 10, 20, 30, 40, 50 };
	double d2[] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
	string d3[] = { "apple", "lemon", "grape", "pineapple", "banana" };


	Graph<int> g1("File1.bin", d1);
	Graph<double> g2("File2.bin", d2);
	Graph<string> g3("File3.bin", d3);

	g1.print();
	bool connect = g1.connected();
	if (connect) cout << "Graph is connected" << endl;
	else cout << "Graph is not connected" << endl;
	int l1 = g1.listDistance(1, 3);
	cout << "Distance is : " << l1 << endl;
	cout << endl << "******" << endl;


	g2.print();
	connect = g2.connected();
	if (connect) cout << "Graph is connected" << endl;
	else cout << "Graph is not connected" << endl;
	int l2 = g2.listDistance(0, 4);
	cout << "Distance is : " << l2 << endl;
	cout << endl << "******" << endl;


	g3.print();
	connect = g3.connected();
	if (connect) cout << "Graph is connected" << endl;
	else cout << "Graph is not connected" << endl;
	int l3 = g3.listDistance(0, 1);
	cout << "Distance is : " << l3 << endl;
	cout << endl << "******" << endl;



	/*point tr[3] = { { 2,1 },{ 2,5 },{ 5,1 } };
	triangle t;
	cout << "Triangle" << endl;
	t.print();
	cout << "Is Triangle: " << t.isFigure() << endl;
	cout << "Is right triangle: " << t.isRightTriangle() << endl;
	cout << "Is isoscenceles Triangle: " << t.isIsoscelesTriange() << endl;
	cout << "Is equilateral triangle: " << t.isEquilateral() << endl;
	cout << "Perimeter: " << t.perimeter() << endl;
	cout << "Area: " << t.area() << endl << endl;

	point qua[] = { { 2,6 },{ 4,8 },{ 8,4 },{ 2, 6 } };
	quadrangle q;
	cout << "Quadrangle" << endl;
	q.print();
	cout << "Is trapeze: " << q.isTrapeze() << endl;
	cout << "Is parallelogram: " << q.isParallelogram() << endl;
	cout << "Is rhombus: " << q.isRhombus() << endl;
	cout << "Is rectangular: " << q.isRectangle() << endl;
	cout << "Is square: " << q.isSquare() << endl;
	cout << "Perimeter: " << q.perimeter() << endl;
	cout << "Area: " << q.area() << endl << endl;


	pentagon p;
	cout << "Pentagon" << endl;
	p.print();
	cout << "Is right: " << p.isRight() << endl;
	cout << "Perimeter: " << p.perimeter() << endl;
	cout << "Area: " << p.area() << endl;*/

	system("pause");
	return 0;
}
