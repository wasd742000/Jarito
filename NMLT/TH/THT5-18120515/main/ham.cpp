#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ham.h"
#include <math.h>

void menu(int &choice){
	printf("\n\nMENU_____________________\n");
	printf("1.Kiem tra nam nhuan.\n2.Kiem tra tinh hop le cua ngay.\n3.Xuat ngay hom truoc/sau.\n4.Tinh so ngay trong thang/ nam.\n5.Tinh khoang cach giua 2 khoang thoi gian theo ngay/ thang/ nam.\n6.Thoat.\nLua chon cua ban: ");
	scanf("%d", &choice);
	printf("\n----->>Load CT %d: \n", choice);
}

//Cac CT chinh 

void ct1(){
	int nam;
	printf("Nhap nam = ");
	scanf("%d", &nam);
	if (ktnamnhuan(nam)){
		printf("%d la nam nhuan.\n", nam);
	}
	else{
		printf("%d khong phai la nam nhuan.\n", nam);
	}
}

void ct2(){
	int d, m, y;
	nhap(d, m, y);
	if (kthople(d, m, y)){
		printf("HOP LE.\n");
	}
	else{
		printf("KHONG HOP LE !\n");
	}
}

void ct3(){
	int d, m, y;
	nhap(d, m, y);
	trangay(d, m, y);
}

void ct4(){
	int m, y;
	printf("Nhap thang, nam : ");
	scanf("%d%d", &m, &y);
	printf("So ngay trong thang = %d.\n",songay(m, y));
}
void ct5(){
	int d1, d2, m1, m2, y1, y2;
	printf("Nhap vao 2 thoi diem.\n");
	nhap(d1, m1, y1);
	nhap(d2, m2, y2);
	float a = spand(d1, m1, y1, d2, m2, y2);
	float b = spanm(d1, m1, y1, d2, m2, y2);
	float c = spany(d1, m1, y1, d2, m2, y2);
	printf("Khoang thoi gian: \nTheo ngay = %.3f\nTheo thang = %.3f\nTheo nam = %.3f\n", a, b, c);
}

void nhap(int &d, int &m, int &y){
	printf("Nhap ngay, thang, nam : ");
	scanf("%d%d%d", &d, &m, &y);
}

bool ktnamnhuan(int y){
	if ((y % 100 == 0 && y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)){
		return 1;
	}
	else{
		return 0;
	}
}

bool kthople(int d, int m, int y){
	if (d > 0 && m > 0 && y > 0){
		switch (m){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d > 31){
				return 0;
			}
			else {
				return 1;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (d > 30){
				return 0;
			}
			else {
				return 1;
			}
			break;
		case 2:
			if (ktnamnhuan(y)){
				if (d > 29){
					return 0;
				}
				else {
					return 1;
				}
			}
			else{
				if (d > 28){
					return 0;
				}
				else{
					return 1;
				}
			}
			break;
		default:
			return 0;
			break;
		}
	}
	else{
		return 0;
	}
}

//2 ham con cua "trangay"
void xuatngaytruoc(int d, int m, int y){
	int dd, mm, yy;
	if (d == 1){
		switch (m){
		case 1:
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			dd = 31;
			if (m == 1){
				yy = y - 1;
				mm = 12;
			}
			else{
				yy = y;
				mm = m - 1;
			}
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			dd = 30;
			mm == m - 1;
			yy = y;
			break;
		case 3:
			mm = m - 1;
			yy = y;
			if (ktnamnhuan(y)){
				dd = 29;
			}
			else{
				dd = 28;
			}
			break;
		}
	}
	else{
		dd = d - 1;
		mm = m;
		yy = y;
	}
	printf("Ngay hom truoc la: %d / %d / %d.\n", dd, mm, yy);
}

void xuatngaysau(int d, int m, int y){
	int dd, mm, yy;
	switch (m){
	case 1:
	case 3: 
	case 5: 
	case 7:
	case 8:
	case 10:
	case 12:
		if (d == 31){
			dd = 1;
			if (m == 12){
				yy = y + 1;
				mm = 1;
			}
			else{
				yy = y;
				mm = m + 1;
			}
		}
		else{
			dd = d + 1;
			mm = m;
			yy = y;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (d == 30){
			yy = y;
			mm = m + 1;
			dd = 1;
		}
		else{
			dd = d + 1;
			mm = m;
			yy = y;
		}
		break;
	case 2:
		yy = y;
		if (ktnamnhuan(y)){
			if (d == 29){
				dd = 1;
				mm = m + 1;
		}
			else{
				dd = d + 1;
				mm = m;
			}
		}
		else{
			if (d == 28){
				dd = 1;
				mm = m + 1;
			}
			else{
				dd = d + 1;
				mm = m;
			}
		}
		break;
	}
	printf("Ngay hom sau la : %d / %d / %d.\n ", dd, mm, yy);
}

void trangay(int d, int m, int y){
	if (kthople(d, m, y)){
		xuatngaytruoc(d, m, y);
		xuatngaysau(d, m, y);
	}
	else{
		printf("Nhap sai !\n ");
	}
}

int songay(int m, int y){
	switch (m){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (ktnamnhuan(y)){
			return 29;
		}
		else{
			return 28;
		}
		break;
	}
}
 
float spand(int d1, int m1, int y1, int d2, int m2, int y2){
	float span = abs((y1 - y2) * 365 + (m1 - m2) * 30 + d1 - d2 );
	return span;
}

float spanm(int d1, int m1, int y1, int d2, int m2, int y2){
	float span = abs((y1 - y2) * 12 + m1 - m2 + float(d1 - d2) / 30);
	return span;
}

float spany(int d1, int m1, int y1, int d2, int m2, int y2){
	float span = abs(y1 - y2 + float(m1 - m2) / 12 + float(d1 - d2) / (365));
	return span;
}