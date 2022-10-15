//Bai 7.3.1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void main(){
	int n, i = 1, t;
	printf("Nhap so n = ");
	scanf("%d", &n);
	while (i <= n){
		if (i*i == n){
			t = 1;
			break;
		}
		else{
			t = 0;
			i++;
		}
	}
	if (t){
		printf("%d la so chinh phuong.\n", n);
	}
	else{
		printf("%d khong la so chinh phuong.\n", n);
	}
}