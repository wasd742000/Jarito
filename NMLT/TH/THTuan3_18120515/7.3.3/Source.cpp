//Bai 7.3.3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n, sum = 0, i = 1;
	printf("Nhap n = ");
	scanf("%d", &n);
	while (i < n){
		if (n % i == 0){
			sum += i;
			i++;
		}
		else{
			i++;
		}
	}
	if (sum == n){
		printf("%d la so hoan thien.\n", n);
	}
	else{
		printf("%d khong phai la so hoan thien.\n", n);
	}
}