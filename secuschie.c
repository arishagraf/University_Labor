#include <stdio.h>
#include <math.h>
#include <conio.h>

double find( double x_curr,double x_prev  , double e);
double func(double x);

int main() 
{
	double x0=1.6;
	double x1=2;
	double e =0.0001;
	double x=find(x0,x1,e);
  printf("Poluchen rezultat %lf ",x);
  double pogreshnost = func(x);
  printf("Poluchena pogreshnost %lf ", pogreshnost);

 return 0;
}

double find(double x_curr,double x_prev , double e)
{
	double x1, x2, res=0, y=0;
	x1 = x_curr;
	x2 = x_prev;
	do
	{
		y = res;
		res = x2 - ((x2 - x1) / (func(x2) - func(x1))) * func(x2);
		x1 = x2;
		x2 = res;
	} while (fabs(y - res) >= e);
  	return res;
}

double func(double x)
{
	return((log(x))*(log(x))+cos(x*x+x/3));
}






