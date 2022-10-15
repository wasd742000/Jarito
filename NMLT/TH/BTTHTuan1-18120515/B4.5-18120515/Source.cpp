#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <math.h>
void main()
{
	double r, chuvi, dientich;
	printf("Nhap vao ban kinh cua hinh tron = ");
	scanf("%lf", &r);
	chuvi = 2 * M_PI*r;
	dientich = M_PI*pow(r, 2);
	printf("Chu vi hinh tron = %.1lf \nDien tich hinh tron = %.1lf \n", chuvi, dientich);

}
