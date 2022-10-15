#define _CRT_SECURE_NO_WARNINGS
#include "xl1.h"
#include "xl2.h"
#include <stdio.h>

void nhap(int &a, int &n){
	printf("Don thuc dang ax^n, nhap a, n: ");
	scanf("%d%d", &a, &n);
}

void outb4(int a1, int n1, int a2, int n2){
	int ticha, tichn, thuongn, dha1, dhn1, dha2, dhn2;
	ticha = a1 * a2;
	tichn = n1 + n2;
	thuongn = n1 - n2;
	dha1 = a1 * n1;
	dhn1 = n1 - 1;
	dha2 = a2 * n2;
	dhn2 = n2 - 1;
	printf("\nTich 2 don thuc = %dax^%d.\n", ticha, tichn);
	rutgonps(a1, a2);
	printf("\nThuong 2 don thuc = (%d / %d)ax^%d . \n", a1, a2, thuongn);
	printf("\nDao ham 2 don thuc = %da^%d va %da^%d \n", dha1, dhn1, dha2, dhn2);
}


	