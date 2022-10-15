//Bai 5.1: tim so nho nhat trong hai so.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int a, b;
	printf("Nhap 2 so a, b : ");
	scanf("%d%d", &a, &b);
	if (a < b){
		printf("So nho nhat la %d.\n ", a);
	}
	else{
		printf("So nho nhat la %d.\n", b);
	}

}
