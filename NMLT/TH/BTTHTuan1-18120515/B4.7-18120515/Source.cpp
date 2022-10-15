#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void main()
{
	double x, y1, y2, x2;
	printf("Nhap x = ");
	scanf("%lf", &x);
	x2 = pow(x, 2.0);
	y1 = 4 * (x2 + 10 * pow(x, 3.0 / 2) + 3 * x + 1);
	y2 = (sin(M_PI*x2) + pow(x2 + 1, 1.0 / 2)) / (pow(exp(1.0), 2*x) + cos((M_PI*x) / 4));
	printf(" y1 = %.2lf\n", y1);
	printf(" y2 = %.2lf\n", y2);
}