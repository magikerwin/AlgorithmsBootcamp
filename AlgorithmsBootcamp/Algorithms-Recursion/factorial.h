#pragma once

namespace factorial
{

int factorial(int n)
{
	if (n == 1) return 1;
	return n * factorial(n - 1);
}

int factorialAccumulator(int n, int accumulator)
{
	if (n == 1) return accumulator;
	return factorialAccumulator(n-1, n * accumulator);
}

}