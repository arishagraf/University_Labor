
#include <stdio.h>
#include <math.h>
#include <conio.h>

/*************************************************************************
Метод Рунге-Кутта четвертого порядка для решения уравнения первого порядка.


Алгоритм решает диффур y'=F(x,y) методом Рунге-Кутта 4 порядка.

Начальная точка имеет кординаты (x,y),
конечная - (x1, RungeKutt(x, x1, y, n)).

До конечной точки мы добираемся через n промежуточных
с постоянным шагом h=(x1-x)/n
*************************************************************************/
double solveoderungekutta(double x, double x1, double y, double h);
double f(double x, double y);
double f_tochnoe(double x);
int main()
{
	double x=0;
	double x1=1;
	double y=0;
	double h = 0.05;
    printf("x \t");
    printf("y tochnoe \t");
    printf("y priblizhennoe \n");
    double res = 0;
    while (x <= x1)
    {
        printf("%f \t %f \t %f \n", x,f_tochnoe(x),res);
        res = solveoderungekutta(x, x1, y, h);
        x += 0.05;
        y = res;
    }
	return 0;
}
double solveoderungekutta(double x, double x1, double y, double h)
{
    double result;
    double y1;
    double k1;
    double k2;
    double k3;
        y1 = y;
        k1 = h*f(x, y);
        x = x+h/2;
        y = y1+k1/2;
        k2 = f(x, y)*h;
        y = y1+k2/2;
        k3 = f(x, y)*h;
        x = x+h/2;
        y = y1+k3;
        y = y1+(k1+2*k2+2*k3+f(x, y)*h)/6;
        //y1 = y;
        result = y;
    return result;
}

double f(double x, double y)
{
	return (3*x*x*y+(pow(x,2)+pow(x,5))/3); 
}

double f_tochnoe(double x) 
{
    return (((2*exp(pow(x,3))-pow(x,3)-2))/9);
}
