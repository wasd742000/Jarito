//Bai 7.2.2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n;
	do{
		printf("Nhap nam = ");
		scanf("%d", &n);
	} while (n >= 2018);
	printf("nam = %d\n", n);
}