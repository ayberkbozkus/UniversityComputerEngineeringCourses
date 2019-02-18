#include <studio.h> //printf, scanf
#include <stdlib.h> //EXIT_SUCCESS 
int main ()
{
	double fahrenheit = 0.0;
	printf("Enter tempetare (in Fahrenheit) : ");
	scanf("%lf", &fahrenheit);

	double celsius = (5.0 / 9.0) * (fahrenheit - 32);
	printf("Teperature (in Celsius) : %.2f\n", celsius);
	
	return EXIT_SUCCESS;

}