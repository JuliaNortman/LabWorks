#include "modCntrl.h"
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main()
{
	modCntrl mc;
	//mc.output();
	mc.countS();
	mc.countP();
	mc.countA();
	mc.countResult();
	std::cout << std::endl;
	mc.output();
	system("pause");
	return 0;
}