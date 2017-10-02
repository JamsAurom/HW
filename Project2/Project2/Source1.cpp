#include <iostream>
#include <cmath>
#include <math.h>
#include "Header.h"

double pi = 3.14159265359;

double fact(double n);

double topi(double x)
{
	int i;
	i = (int) (x / pi);
	x = x - (double)(pi*i);
	return x;
}

double cosin(double x, double pogr) {
	double k = -1; double chlen = 0; double n = 1;
	double xn = x*x; double summ = 1;
	do {                                //цикл разложени€ в р€д
		summ += chlen;
		chlen = (k*xn) / fact(2 * n);
		n++; k = -k; xn *= x*x;
	} while (fabs(chlen)>pogr); //пока член больше погрешности
	return summ;
}

double fact(double n)
{
	double fac = 1;
	for (int i = 1; i <= n; i++)
		fac *= i; 
	return fac;
}




