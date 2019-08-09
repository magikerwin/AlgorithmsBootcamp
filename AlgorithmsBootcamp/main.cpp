#include <iostream>
//#include "Algorithms-Recursion/recursion.h"
//#include "Algorithms-Recursion/factorial.h"
//#include "Algorithms-Recursion/fibonacci.h"
#include "Algorithms-Recursion/binarySearch.h"

int main()
{
	int test[5] = {1,2,3,10,50};
	std::cout << "Ans=" << binarySearch::binarySearch(test,0,5-1,10) << std::endl;
	std::system("pause");
	return 0;  

}