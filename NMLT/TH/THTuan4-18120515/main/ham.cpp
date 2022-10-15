#define _CRT_SECURE_NO_WARNINGS
#include "ham.h"
#include <stdio.h>
#include <math.h>

void menu(int &choice){
	printf("\n___________________________________________________________________________________\n");
	printf("*MENU* - chon mot bai tap !\n");
	for (int i = 1; i < 12; i++){
		printf("%d) Bai tap %d.\n", i, i);
		}
	printf("12) Thoat.\n_______________________\nLua chon cua ban la: ");
	scanf("%d", &choice);
	printf("\n-------> Tai bai tap %d\n", choice);
}


void nhapn(int &n){
	printf("Nhap n = ");
	scanf("%d", &n);
}

void nhapx(float &x){
	printf("Nhap x = ");
	scanf("%f", &x);
}

void inso(int n){
	printf("So thoa man: %d \n", n);
}

bool ktuoc(int n, int i){
	if (n % i == 0){
		return 1;
	}
	else{
		return 0;
	}
}

bool ktnt(int n){
	if (n == 2){
		return 1;
	}
	else if (n < 2){
		return 0;
	}
	else if (n % 2 == 0){
		return 0;
	}
	else{
		for (int i = 3; i <= (n - 1); i++){
			if (n % i == 0){
				return 0;
				break;
			}
			else{
				return 1;
			}
		}
	}
}

bool ktdx(long n){
	long reverse = 0;
	int temp = n;
	while (temp >= 1){
		reverse *= 10;
		reverse += temp % 10;
		temp /= 10;
	}
	if (reverse == n){
		return 1;
	}
	else{
		return 0;
	}
}

long giaithua(int n){
	long gt = 1;
	for (int i = 1; i <= n; i++){
		gt *= i;
	}
	return gt;
}

float Power(float x, int n){
	float r = 1;
	for (int i = 1; i <= n; i++){
		r *= x;
	}
	return r;
}

int delta(int a, int b, int c){
	int d = b * b - 4 * a * c;
	return d;
}

void hept2an(int a, int b, int c, int d, int e, int f){
	float x1, x2;
	x1 = float(f * a - d * c) / (e * a - d * b);
	x2 = (c - (b * x1)) / a;
	printf("Nghiem x1 = %.3f\n", x1);
	printf("Nghiem x2 = %.3f\n", x2);
}

void nhaplong(long &l){
	printf("Nhap so = ");
	scanf("%ld", &l);
}

void docso(long so ){
	int cso;
	long somoi = 0 ;
	do {
		somoi *= 10;
		somoi += so % 10;
		so /= 10;
		
	} while (so >= 1);
	while (somoi >= 1){
		cso = somoi % 10;
		switch (cso){
		case 0:
			printf(" khong ");
			break;
		case 1:
			printf(" mot ");
			break;
		case 2:
			printf(" hai ");
			break;
		case 3:
			printf(" ba ");
			break;
		case 4:
			printf(" bon ");
			break;
		case 5:
			printf(" nam ");
			break;
		case 6:
			printf(" sau ");
			break;
		case 7:
			printf(" bay ");
			break;
		case 8:
			printf(" tam ");
			break;
		case 9:
			printf(" chin ");
			break;
		}
		somoi /= 10;
	}
}
