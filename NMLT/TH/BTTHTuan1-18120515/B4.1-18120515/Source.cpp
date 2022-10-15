#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	float a, b, thuong;
	printf("Nhap so nguyen a = ");
	scanf("%d", &a);
	printf("Nhap so nguyen b = ");
	scanf("%d", &b);
	if (b == 0)
	{
		printf("Khong tinh duoc do mau bang 0\n");
	}
	else{
		thuong = a / b;
		printf("Thuong = %.1f \n",thuong);
	}

}