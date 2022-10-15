//Bai 7.1.1: tinh n!
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n, s = 1;
	printf("Nhap n = ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		s *= i;
	}
	printf("n! = %d\n", s);
}