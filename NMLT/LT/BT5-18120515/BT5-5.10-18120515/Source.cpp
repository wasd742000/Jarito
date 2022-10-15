//Bai 5.10: in day Fibonaci
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n, so1 = 0, so2 = 1 , so3;
	printf("Nhap n = ");
	scanf("%d", &n);
	if (n == 0){
		printf("f(0) = 0\n");
	}
	else if (n == 1){
		printf("f(0) = 0\nf(1) = 1\n");
	}
	else{
		printf("f(0) = 0\nf(1) = 1\n");
		for (int i = 2; i <= n; i++){
			so3 = so1 + so2;
			printf("f(%d) = %d\n", i, so3);
			so1 = so2;
			so2 = so3;
		}
	}
}