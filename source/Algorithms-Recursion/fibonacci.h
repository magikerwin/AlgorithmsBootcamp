#pragma once

#include <iostream>

namespace fibonacci
{
	// Fibonacci numbers:
	// F(0) = 0
	// F(1) = 1
	// F(n) = F(n-1) + F(n2)

	int headFibonacci(int n)
	{
		if (n < 0)
		{
			std::cout << "[WARNING] Input cannot be negative number!" << std::endl;
			return -1;
		}
		if (n == 0) return 0;
		if (n == 1) return 1;
		int fib1 = headFibonacci(n - 1);
		int fib2 = headFibonacci(n - 2);
		
		return fib1 + fib2;
	}

	int tailFibonacci(int n, int current = 1, int prev = 0)
	{
		if (n < 0)
		{
			std::cout << "[WARNING] Input cannot be negative number!" << std::endl;
			return -1;
		}
		if (n == 0) return 0 + prev;

		return tailFibonacci(n-1, current + prev, current);
	}
}