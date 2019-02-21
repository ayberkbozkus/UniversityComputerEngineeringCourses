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
		celcius = tempature
	}
	else if (unit == 'F')
	{
		celcius = (0.5 / 0.9) * (tempature - 32)
	}
	else
	{
		printf("Please enter tempature unit as either C or F. \n")
		return EXIT_FAILURE;
	}


		if (celcius <= 0)
		{
			printf("Water is solid (Ice) at %.2lf degrees %s \n", tempature, unit =='C' ? "Celcius" : "Fahrenheit");
		}
		else if ( celcius <100 )
		{
			printf("Water is Liquid at %.2lf degrees %s \n ", tempature, unit =='C' ? "Celcius" : "Fahrenheit");
		}
		else
		{
			printf("Water is Gas at %.2lf degrees %s \n", tempature, unit =='C' ? "Celcius" : "Fahrenheit");
		}
	return EXIT_SUCCESS;
}
