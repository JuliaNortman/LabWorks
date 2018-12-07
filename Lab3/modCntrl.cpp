#include "modCntrl.h"



modCntrl::modCntrl()
{
	cout << "Enter the dimension of matrix A: ";
	cin >> n;
	A = MatrixXd(n, n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> A(i, j);
		}
	}
	cout << "Enter the number of columns of matrix B: ";
	cin >> m;
	B = MatrixXd(n, m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> B(i, j);
		}
	}
}


modCntrl::~modCntrl()
{
}

void modCntrl::countS()
{
	scol = n * m;
	S = MatrixXd(n, scol);
	int start = 0;
	for (int i = 0;i < n; ++i)
	{
		for (int j = start; j < m; ++j)
		{
			S(i, j) = B(i, j);
		}
	}
	start = start + m;
	for (int i = 1; i < n; ++i)
	{
		MatrixXd Amult(n, n);
		Amult = A;
		for (int j = 2; j <= i; ++j)
		{
			Amult = Amult * A;
		}
		

		MatrixXd tmp(n, m);
		tmp = Amult * B;
		for (int k = 0; k < n; ++k)
		{
			for (int l = start; l < m + start; ++l)
			{
				S(k, l) = tmp(k, l-start);
			}
		}
		start = start + m;
	}
	S = S.inverse();
}

void modCntrl::output()
{
	cout << S;
}