#include"stdafx.h"
#include"w32.h"
#define PI 3.1415926
int factorial(int n)
{
	

	if (n == 0)
		return 1;

		return n*factorial(n - 1);
	

}
	float FAC::convert(float deg) {
		double i;
		i = (deg / 180)*PI;
		return i;
	}

