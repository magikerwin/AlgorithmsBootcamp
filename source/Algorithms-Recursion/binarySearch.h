#pragma once
 
#include <iostream>

namespace binarySearch
{
	int binarySearch(int nums[], int begin, int end, int num)
	{	if (begin > end)
		{
			std::cout << "[WARNING] Range error!" << std::endl;
			return -1;
		}

		int middle = begin + (end - begin) / 2;

		if (nums[middle] == num) return middle;

		if (num < nums[middle])
		{
			return binarySearch(nums, begin, middle-1, num);
		}
		else {
			return binarySearch(nums, middle+1, end, num);
		}
	}
}

// [sample.cpp]
// int test[5] = {1,2,3,10,50};
// std::cout << "Ans=" << binarySearch::binarySearch(test, 0, 5 - 1, 10) << std::endl;
