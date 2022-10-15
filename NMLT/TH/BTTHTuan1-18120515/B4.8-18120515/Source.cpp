#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	int tien, a, b , c;
	printf("Nhap so tien = ");
	scanf("%d", &tien);
	a = tien / 10;
	b = (tien % 10) / 5;
	c = ((tien % 10))%5 / 1;
	printf("So to 10d = %d\nSo to 5d = %d \n So to 1d = %d\n", a, b, c);

	

}