//Bai 7.2.1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n;
	do{
		printf("Nhap n = ");
		scanf("%d", &n);
	} while (n < 0);
	printf("n = %d\n",n);
}