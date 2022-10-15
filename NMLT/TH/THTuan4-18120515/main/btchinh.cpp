#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "ham.h"
#include "btchinh.h"
void b1(){
	int n;
	printf("CT in ra cac uoc so cua n\n");
	nhapn(n);
	for (int i = 1; i <= n; i++){
		if (ktuoc(n, i)){
			inso(i);
		}
	}
}

void b2(){
	int n;
	printf("CT in ra cac uoc so nguyen to cua n\n");
	nhapn(n);
	for (int i = 2; i <= n; i++){
		if (ktuoc(n, i) && ktnt(i)){
			inso(i);
		}
	}
}

void b3(){
	int n;
	printf("CT in ra cac so nguyen to < n\n");
	nhapn(n);
	for (int i = 2; i < n; i++){
		if (ktnt(i)){
			inso(i);
		}
	}
}

void b4(){
	printf("CT in so doi xung < n.\n");
	long so;
	nhaplong(so);
	for (int i = 11; i < so; i++){
		if (ktdx(i)){
			inso(i);
		}
	}
}

void b5(){
	printf("CT tinh so to hop chap k cua n.\n");
	long r;
	int n, k;
	nhapn(n);
	printf("Nhap k = ");
	scanf("%d", &k);
	r = giaithua(n) / (giaithua(k)*giaithua(n - k));
	printf("So to hop chap k cua n = %ld\n", r);
}

void b6(){
	printf("CT tinh S theo cong thuc.\n");
	int n;
	float x, s = Power(1.5, 8);
	nhapx(x);
	nhapn(n);
	for (int i = 1; i <= n; i++){
		s += (Power(-1, i) * Power((x + i), i)) / Power(i, 2);
	}
	printf("S = %.3f", s);
}

void b7(){
	printf("CT tinh S = e^x\n");
	int n;
	float x, s = 1;
	nhapx(x);
	nhapn(n);
	for (int i = 1; i <= n; i++){
		s += Power(x, i) / giaithua(i);
	}
	printf("e^x = S = %.3f\n", s);
}


void b8(){
	int a, b, c, d;
	printf("Nhap a, b, c cua pt bac 2: ");
	scanf("%d%d%d", &a, &b, &c);
	d = delta(a, b, c);
	if (a == 0){
		printf("PT co nghiem duy nhat x = %.3f\n", -float(c) / b);
	}
	else{
		if (d > 0){
			float x1 = (-b + sqrt(float(d))) / (2 * a);
			float x2 = (-b - sqrt(float(d))) / (2 * a);
			printf("PT co 2 nghiem phan biet:\nx1 = %.3f\nx2 = %.3f", x1, x2);
		}
		else if (d == 0){
			printf("PT co nghiem kep x1 = x2 = %.3f\n", -float(b) / (2 * a));
		}
		else{
			printf("PT vo nghiem!\n");
		}
	}
}

void b9(){
	int a, b, c, d, e, f;
	printf("Giai he PT 2 an.\nNhap a, b, c, d, e, f: ");
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	hept2an(a, b, c, d, e, f);
}

void b10(){
	long so1, so2, so3;
	printf("Nhap 3 so: so co 1 chu so, so co 3 chu so, so < 1000000\n");
	nhaplong(so1);
	docso(so1);
	printf("\n");
	nhaplong(so2);
	docso(so2);
	printf("\n");
	nhaplong(so3);
	docso(so3);
}

void b11(){
	int chon, ndo;
	float cdoi;
	printf("Doi nhiet do. Chon cach chuyen doi: \n1) Do C -----> do F.\n2) Do F -----> do C.\n________________\nLua chon cua ban: ");
	scanf("%d", &chon);
	if (chon == 1){
		printf("Nhap do C = ");
		scanf("%d", &ndo);
		cdoi = float(9 * ndo) / 5 + 32;
		printf("Do F = %.3f", cdoi);
	}
	else if (chon == 2){
		printf("Nhap do F = ");
		scanf("%d", &ndo);
		cdoi = float(5 * (ndo - 32)) / 9;
		printf("Do C = %.3f", cdoi);
	}
	else{
		printf("Nhap sai !\n");
	}
}