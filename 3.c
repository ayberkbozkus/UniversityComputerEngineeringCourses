#include <stdio.h>
#include <math.h>
int main ()
{
	double height = 0.0;
	double weight = 0.0;
	printf("Enter Height and Weight : ");
	scanf("%lf %lf", &height, &weight);
	bsa = 0.0003207 * pow (height,0.3) * pow (weight,(0.7285-(0.0188*log(weight,10))))
	printf("Your BSA %f", bsa);
	return 0;
}