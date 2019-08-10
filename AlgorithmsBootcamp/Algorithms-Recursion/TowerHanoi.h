#pragma once

#include <iostream>

namespace towerHanoi
{
	int headTowerHanoi(int n)
	{
		if (n < 0)
		{
			std::cout << "[WARNING] Input cannot be nagtive number." << std::endl;
			return -1;
		}

		if (n == 0) return 0;
		if (n == 1) return 1;
		
		return 1 + 2 * headTowerHanoi(n-1);
	}

	void getSolution(int n, std::string srcRod, std::string tmpRod, std::string dstRod)
	{
		if (n < 1)
		{
			std::cout << "[WARNING] Input must be bigger than 1." << std::endl;
			return;
		}
		
		if (n == 1)
		{
			std::cout << "move plate " << n << " from " << srcRod.c_str() << " to " << dstRod.c_str() << std::endl;
			return;
		}
		
		getSolution(n - 1, srcRod, dstRod, tmpRod);
		std::cout << "move plate " << n << " from " << srcRod.c_str() << " to " << dstRod.c_str() << std::endl;
		getSolution(n - 1, tmpRod, srcRod, dstRod);
	}
}

// [sample.cpp]
// std::cout << "Ans=" << towerHanoi::headTowerHanoi(3) << std::endl;
// towerHanoi::getSolution(3, "A", "B", "C");
