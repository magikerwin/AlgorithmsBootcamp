#include <iostream>
//#include "Algorithms-Recursion/recursion.h"
//#include "Algorithms-Recursion/factorial.h"
//#include "Algorithms-Recursion/fibonacci.h"
//#include "Algorithms-Recursion/binarySearch.h"
//#include "Algorithms-Recursion/towerHanoi.h"
#include "Algorithms-Backtracking/n-queens.h"


int main()
{
	nQueens::NQueensProblem problem(4);
	problem.solve();

	std::system("pause");
	return 0;  

}