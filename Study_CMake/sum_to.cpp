#include "functions.h"

int sum_to(int n)
{
	if (n > 0)
	{
		return n + sum_to(n - 1);
	}
	else
	{
		return 0;
	}
}
