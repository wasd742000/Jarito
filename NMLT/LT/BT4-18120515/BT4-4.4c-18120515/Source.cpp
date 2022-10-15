//Bai 4.4 c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n;
	float kq = 0;
	printf("Nhap n = ");
	scanf("%d", &n);
	if (n >= 0){
		for (int i = n; i >= 0; i--){
			if(i % 2 == 0){
				kq += 1 / (float)(2 * i + 1);
			}
			else{
				kq -= 1 / (float)(2 * i + 1);
			}
		}
		printf("PI = %.2f\n", kq*4);
	}
	else{
		printf("n phai nguyen duong !");
	}

}