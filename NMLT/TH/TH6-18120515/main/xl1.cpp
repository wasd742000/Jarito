#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "xl1.h"
#include "xl2.h"
#define N 100

void menu(int &c){
	printf("\n_____________MENU__________________\n");
	for (int i = 1; i < 18; i++){
		printf("%d/ Bai tap %d.\n", i, i);
	}
	printf("18/ Thoat.\n_____________________________________\n");
	printf("Lua chon: ");
	scanf("%d", &c);
	if (c != 18){
		printf("\n---> Tai BT %d ....\n", c);
	}
	else{
		printf("\nThoat .......\n");
	}
}


void b1(){
	int a[N], n;
	nhapmang(a, n);
	xuatb1(a, n);
}

void b2(){
	int a[N], n;
	nhapmangduong100(a, n);
	if (!tbchan(a, n)){
		printf("Khong co so chan nao.\n");
	}
	else{
		printf("Trung binh cong cac so chan = %.3f\n", tbchan(a, n));
	}
}

void b3(){
	int a[N], n;
	nhapmang100(a, n);
	printf("Trung binh cong cac so am = %.3f\nTrung binh cong cua cac so duong = %.3f\n", tbam(a, n), tbduong(a, n));
	printf("Cac so nguyen to trong mang la : \n");
	for (int i = 0; i < n; i++){
		if (ktnt(a[i])){
			printf(" %d ", a[i]);
		}
	}
	sxtangchan(a, n);
}

void b4(){
	int a[N], n;
	nhapmang(a, n);
	kttanggiam(a, n);
}

void b5(){
	int a[N], n, x;
	nhapmang(a, n);
	printf("Nhap 1 so nguyen x = ");
	scanf("%d", &x);
	if (!demx(a, n, x)){
		printf("%d khong xuat hien trong mang.\n", x);
	}
	else{
		printf("%d xuat hien %d lan trong mang.\n", x, demx(a, n, x));
	}
	xoax(a, n, x);
	printf("Xoa %d ra khoi mang.\nMang sau khi xoa: ", x);
	for (int i = 0; i < n; i++){
		printf(" %d ", a[i]);
	}
}

void b6(){
	int a[N], n, x;
	nhapmang(a, n);
	sxtang(a, n);
	printf("Thu tu tang dan cua mang : \n");
	for (int i = 0; i < n; i++){
		printf("a[%d] = %d\n ", i, a[i]);
	}
	printf("\nNhap x = ");
	scanf("%d", &x);
	chenxtt(a, n, x);
	printf("\n");
	for (int i = 0; i < n; i++){
		printf("a[%d] = %d\n ", i, a[i]);
	}
}

void b7(){
	int a[N], n;
	nhapmangduong100(a, n);
	sxtang(a, n);
	printf("Mang tang dan: \n");
	for (int i = 0; i < n; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	xoatrung(a, n);
	printf("Loai bo cac phan tu trung nhau: \n");
	for (int i = 0; i < n; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void b8(){
	int a[N], n, k;
	nhapmangduong100(a, n);
	printf("Tinh trung binh cong cac phan tu >= k. Nhap k = ");
	scanf("%d", &k);
	printf("Trung binh cong = %.3f", tbk(a, n, k));
}

void b9(){
	int a[N], n;
	nhapmangduong100(a, n);
	sxb9(a, n);
	printf("Sap xep cac so le tang dan o dau, cac so chan giam dan o cuoi:\n");
	for (int i = 0; i < n; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void b10(){
	int a[N], n, p, k;
	nhapmangduong100(a, n);
	printf("CT huy k phan tu trong mang, bat dau p. Nhap 2 so nguyen duong p, k = ");
	scanf("%d%d", &p, &k);
	huymang(a, n, p, k);
	printf("Mang sau khi huy : \n");
	for (int i = 0; i < n; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void b11(){
	int a[N], b[N], na, nb, p;
	printf("CT chen mang B vao mang A tai vi tri p.\n");
	printf("Mang A: \n");
	nhapmang(a, na);
	printf("Mang B: \n");
	nhapmang(b, nb);
	printf("Nhap so nguyen p = ");
	scanf("%d", &p);
	chenmangp(a, b, na, nb, p);
	printf("Mang sau khi chen : \n");
	for (int i = 0; i < na; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void b12(){
	int a[N], b[N], na, nb;
	printf("CT gop hai mang A va B xen ke.\nNhap mang A: ");
	nhapmang(a, na);
	printf("Nhap mang B: ");
	nhapmang(b, nb);
	xenke(a, b, na, nb);
	printf("Mang sau khi gop: \n");
	for (int i = 0; i < na; i++){
		printf("\na[%d] = %d\n", i, a[i]);
	}
	xoatrung(a, na);
	printf("\nXoa cac phan tu trung nhau trong mang: \n");
	for (int i = 0; i < na; i++){
		printf("\na[%d] = %d\n", i, a[i]);
	}
}

void b13(){
	int a[N], n, vt = 0, l = 0;
	nhapmang(a, n);
	printf("So mang con tang trong mang = %d\n", demcontang(a, n));
	if (demcontang(a, n) != 0){
		mangcontangmax(a, n, vt, l);
		printf("\nMang con tang dai nhat: \n");
		for (int i = vt; i < vt + l; i++){
			printf("a[%d] = %d\n", i, a[i]);
		}
	}
}

void b14(){
	int a[N], b[N], na, nb;
	printf("Kiem tra mang doi xung.\nNhap mang A: \n");
	nhapmang(a, na);
	if (ktdx(a, na)){
		printf("Mang A doi xung.\n");
	}
	else{
		printf("Mang A khong doi xung.\n");
	}
	printf("Nhap mang B: \n");
	nhapmang(b, nb);
	if (demcon(a, b, na, nb) == 0){
		printf("Mang B khong phai la mang con cua A.\n");
	}
	else{
		printf("B la mang con cua mang A.\nSo lan xuat hien cua B trong A = %d", demcon(a, b, na, nb));
	}
}

void b15(){
	float a[N], temp[N], x;
	int n;
	nhapmangr(a, n);
	cpr(a, temp, n);
	sxtangr(a, n);
	printf("Mang sap xep tang dan: \n");
	for (int i = 0; i < n; i++){
		printf("a[%d] = %.2f\n", i, a[i]);
	}
	printf("Phan tu co so lan xuat hien nhieu nhat trong mang la %.2f.\n", xhmaxr(a, n));
	printf("Nhap 1 so thuc x = ");
	scanf("%f", &x);
	if (demxr(a, n, x) == 0){
		printf("%.2f khong ton tai trong mang.\n", x);
		chenxttr(a, n, x);
		printf("Chen %.2f vao mang theo thu tu tang dan: \n", x);
		for (int i = 0; i < n; i++){
			printf("a[%d] = %.2f\n", i, a[i]);
		}
	}
	else{
		invtxh(temp, n, x);
	}
}

void b16(){
	int a[N], n, x;
	nhapmang(a, n);
	sxb16(a, n);
	printf("Mang sap xep cac so le o dau, cac so 0 o giua va cac so chan o cuoi:\n");
	for (int i = 0; i < n; i++){
		printf("\n[%d] = %d\n", i, a[i]);
	}
	printf("\nNhap x = ");
	scanf("%d", &x);
	printf("So nguyen to < x va gan x nhat = %d\n", timb16(a, n, x));
}


void b17(){
	int a[N], n;
	nhapmang(a, n);
	printf("So phan tu la so co 3 chu so va cac chu so tang dan = %d\n", dem3tang(a, n));
}