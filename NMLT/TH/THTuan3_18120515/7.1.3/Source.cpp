#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n;
	float s = 0;
	printf("Nhap n = ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		s += (float)n / (n + 1);
	}
	printf("S = %.2f\n", s);
}