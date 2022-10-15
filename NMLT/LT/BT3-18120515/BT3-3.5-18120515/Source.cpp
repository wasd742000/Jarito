#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void main()
{
	double p, q, s, t, nghiem;
	printf("Nhap p, q = ");
	scanf("%lf %lf",&p,&q);
	s = sqrt((pow(p,6.0)/27) + (pow(q,2.0)/4)); 
	t = q / 2;
	nghiem = (pow(s - t, 1.0 / 3) - pow(s + t, 1.0/3));
	printf("Nghiem x = %.6lf \n", nghiem);

}
