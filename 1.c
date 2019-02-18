#include <stdio.h> // printf,scanf
#include <math.h> // sqrt
int main ()
{
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	printf("Enter coefficients: \n");,
	scanf("%lf %lf %lf", &a, &b, &c);
	double discriminant = b * b - 4 * a * c;
	double x1 = ((-b) + sqrt(discriminant)) / (2 * a);
	double x2 = ((-b) - sqrt(discriminant)) / (2 * a);
	printf("Roots: %f %f \n", x1, x2);
	return 0;
}