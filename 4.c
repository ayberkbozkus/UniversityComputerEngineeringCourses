#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	double tempature;
	char unit; // C, F
	printf("Please enter tempature (end with F for fahrenheit or C for Celsius): \n");
	scanf("%lf %c", &tempature, &unit);
	// double x = 0.0; -> assigment operator
	// == -> comparision operator
	if (unit == 'C')
	{
		if (tempature <= 0)
		{
			printf("Water is solid (Ice) at %.2lf degrees Celsius \n", tempature);
		}
		if ( (tempature > 0) && (tempature <100) )
		{
			printf("Water is Liquid at %.2lf degrees Celsius\n ", tempature );
		}
		if (tempature >= 100)
		{
			printf("Water is Gas at %.2lf degrees Celsius\n", );
		}
	}
		if (unit == 'F')
	{
		if (tempature <= 32)
		{
			printf("Water is solid (Ice) at %.2lf degrees Celsius \n", tempature);
		}
		if ( (tempature > 32) && (tempature <180) )
		{
			printf("Water is Liquid at %.2lf degrees Celsius\n ", tempature );
		}
		if (tempature >= 180)
		{
			printf("Water is Gas at %.2lf degrees Celsius\n", );
		}
	}
	return EXIT_SUCCESS;
}
