#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "xl1.h"
#include "xl2.h"


void in2darray(int a[][100], int &m, int &n){
	printf("Nhap vao ma tran M * N, nhap M va N : ");
	scanf("%d%d", &m, &n);
	printf("Nhap mang: \n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void outb2(int a[][100], int m, int n){
	int sn = 0, sd = 0, dem = 0;
	printf("Cac phan tu co gia tri bang tong cac phan tu con lai tren dong va cot cua no: \n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			sum_x(a, m, n, i, j, sn, sd);
			if (sn == a[i][j] && sd == a[i][j]){
				printf("a[%d][%d] = %d\n", i, j, a[i][j]);
				dem++;
			}
		}
	}
	if (!dem){
		printf("Khong co phan tu nao thoa man !\n");
	}
}