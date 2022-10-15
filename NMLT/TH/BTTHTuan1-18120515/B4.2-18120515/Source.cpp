#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	int so, tong;
	printf("Nhap vao so nguyen co 2 chu so: ");
	scanf("%d", &so);
	tong = so % 10;
	tong = tong + (so / 10) % 10;
	printf("Tong cac chu so = %d \n", tong);
}