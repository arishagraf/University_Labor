#include <stdio.h>
#include <math.h>


double Calculation(double, double, int);
int main()
{
	double a = 1;
	double b = 5;
	int num = 10;
	for (int i = 0; i < 4; i++)
	{

		printf("Pri razbienii intervala na %d poluchen resultat  %lf", num, Calculation(a, b, num));
		printf("\n");
		num *= 4;
	}
	num = 100000;
	printf("Pri razbienii intervala na %d poluchen resultat  %lf \n", num, Calculation(a, b, num));
	printf("Chem menshe interval, tem vishe tochnost vichislenii");
	return 0;
}

double Calculation(double a, double b, int numIntervals)
{
	double result = 0;
	double x = a;
	double step = (a + b) / numIntervals; 
	while (x < b)
	{
		result += (2 * (pow(sin(x+step/2), 2)) + log(x+step/2)) * step; 
		x += step;  
	}

	return result;
}
