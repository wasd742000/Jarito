//Bai 7.1.4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n;
	float s = 0, s1 = 1, s2 = 0;
	printf("Nhap N = ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		s1 *= i;
		s2 += i;
		s += s1 / s2;
	}
	printf("S = %f\n", s);
}