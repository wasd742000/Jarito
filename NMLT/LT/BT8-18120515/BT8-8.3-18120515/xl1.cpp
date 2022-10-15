#define _CRT_SECURE_NO_WARNINGS
#include "xl1.h"
#include <stdio.h>
#include "xl2.h"


void nhapps(int &tu, int &mau){
	printf("Nhap tu so: ");
	scanf("%d", &tu);
	printf("Nhap mau so: ");
	scanf("%d", &mau);
}

void outb3(int tu1, int mau1, int tu2, int mau2){
	int sumtu, summau, protu, promau, rgtu, rgmau;
	// Tong:
	if (mau1 == mau2){
		summau = mau1;
		sumtu = tu1 + tu2;
	}
	else {
		summau = mau1 * mau2;
		sumtu = tu1 * mau2 + tu2 * mau1;
	}
	rutgonps(sumtu, summau);
	//Tich:
	protu = tu1 * tu2;
	promau = mau1 * mau2;
	rutgonps(protu, promau);
	printf("\nTong cua 2 phan so = %d / %d.\n", sumtu, summau);
	printf("\nTich cua 2 phan so = %d / %d.\n\n", protu, promau);
	printf("Hai phan so sau khi nghich dao = %d / %d va %d / %d.\n\n", mau1, tu1, mau2, tu2);
	rutgonps(tu1, mau1);
	rutgonps(tu2, mau2);
	printf("Hai phan so sau khi rut gon = %d / %d va %d / %d.\n\n", tu1, mau1, tu2, mau2);
}