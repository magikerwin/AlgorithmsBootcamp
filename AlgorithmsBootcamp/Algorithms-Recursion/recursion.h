#pragma once

namespace recursion
{

int headRecursionSum(int N)
{
	if (N == 0) return 0;
	return N + headRecursionSum(N - 1);
}

int tailRecursionSum(int N, int result)
{
	if (N == 0) return result;
	return tailRecursionSum(N - 1, N + result);
}

int iterationSum(int N)
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += i;
	}
	return sum;
}

}