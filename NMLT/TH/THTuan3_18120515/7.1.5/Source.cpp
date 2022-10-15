// Bai 7.1.5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void main(){
	int n, x = 0;
	printf("Nhap n = ");
	scanf("%d", &n);
	if (n == 2 ){
		printf("%d la so nguyen to.\n", n);
	}
	else{
		for (int i = 2; i < n; i++){
			if (n % i == 0){
				x = 0;
				break;
			}
			else{
				x = 1;
			}

		}
		if (x){
			printf("%d la so nguyen to.\n", n);
		}
		else{
			printf("%d khong phai la so nguyen to\n", n);
		}
	}
}