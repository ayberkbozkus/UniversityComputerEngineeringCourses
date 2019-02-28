#include <math.h> // fabs
#include <stdio.h> // printf
#include <stdlib.h> // EXIT_SUCCESS

#define EPSILON 0.001
#define ERROR_TOLERANCE 0.001

int main()
{
	double a =1 ;
	double y1,y2;
	double m;
	// we find the root when the error is smaller than Tolerance
	while (fabs(a * x * x + b * x + c) >= ERROR_TOLERANCE)
	{
		y1 = (a * (x - EPSILON) * (x - EPSILON) + b * (x - EPSILON) + c * (x - EPSILON));
		y2 = (a * (x + EPSILON) * (x + EPSILON) + b * (x + EPSILON) + c * (x + EPSILON));
		m = (y2 - y1) / (2 * EPSILON); // derivative(slope)
		// if the derivative at x is 0 then we change it with a very small
		if (!m) // same with (m ! = 0)
		{
			m += EPSILON;
		/*
									(y-y1) = m (x-x1) y =0
									-y1 = m(x-x1)
									x = (-y1/m) +x1
		*/
		x = (-y1 / m) + (x - EPSILON);
		printf("%lf\n", fabs (a * x * x + b * x + c));
		}
	}
	printf("Root : %lf \n ",x);
	return EXIT_SUCCESS;
}