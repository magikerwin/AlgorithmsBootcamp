#include <iostream>
//#include "Algorithms-Recursion/recursion.h"
//#include "Algorithms-Recursion/factorial.h"
//#include "Algorithms-Recursion/fibonacci.h"
//#include "Algorithms-Recursion/binarySearch.h"
#include "Algorithms-Recursion/towerHanoi.h"

int main()
{
	std::cout << "Ans=" << towerHanoi::headTowerHanoi(3) << std::endl;
	towerHanoi::getSolution(3, "A", "B", "C");
	std::system("pause");
	return 0;  

}