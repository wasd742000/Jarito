#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
void main()
{
	double h, r, sday, sxq, v;
	printf("Nhap ban kinh day = ");
	scanf("%lf", &r);
	printf("Nhap chieu cao = ");
	scanf("%lf", &h);
	sday = M_PI*pow(r, 2.0);
	sxq = 2 * M_PI*r*h;
	v = h*sday; 
	printf("Dien tich day hinh tru = %.1lf\nDien tich xung quanh hinh tru = %.1lf\nThe tich hinh tru = %.1lf\n", sday, sxq, v);


}