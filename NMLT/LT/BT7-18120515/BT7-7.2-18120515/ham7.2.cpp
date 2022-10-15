#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ham7.2.h"

void nhapmang(int a[], int &n){
	printf("So so nguyen trong mang = ");
	scanf("%d", &n);
	printf("Nhap mang %d phan tu: \n", n);
	for (int i = 0; i < n; i++){
		printf("Nhap a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}


bool kttangdan(int a[], int n){
	if (n < 1){
		return 0;
	}
	for (int i = 0; i < n - 1; i++){
		if (a[i] > a[i + 1]){
			return 0;
		}
	}
	return 1;
}


bool ktdx(int a[], int n){

	for (int i = 0; i < (n / 2); i++){
		if (a[i] != a[n - 1 - i]){
			return 0;
		}
		return 1;
	}
}

bool ktcsc(int a[], int n){
	if (n < 1){
		return 0;
	}
	int d = a[1] - a[0];
	for (int i = 1; i < n - 1; i++){
		if (a[i + 1] - a[i] != d){
			return 0;
		}
	}
	return 1;
}

void xuatkt(bool a, bool b, bool c){
	if (a){
		printf("Mang tang dan.\n");
	}
	else{
		printf("Mang khong tang dan.\n");
	}

	if (b){
		printf("Mang doi xung.\n");
	}
	else{
		printf("Mang khong doi xung.\n");
	}

	if (c){
		printf("Mang lap thanh cap so cong.\n");
	}
	else{
		printf("Mang khong lap thanh cap so cong.\n");
	}
}