#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 100
#include "xl1.h"


void main(){
	int a[N][N], m, n, pt;
	FILE *f1 = fopen("matrix.txt", "r");

	if (f1 == NULL)
		printf("Khong mo duoc tap tin !\n");
	else{
		printf("Mo thanh cong matrix.txt !\n");
		fscanf(f1, "%d%d", &m, &n);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				fscanf(f1, "%d", &a[i][j]);
			}
		}
		fclose(f1);
	}
	FILE *f2 = fopen("result.txt", "w");
	if (f2 == NULL)
		printf("Khong tao duoc tap tin !\n");
	else{
		printf("Tao thanh cong result.txt !\n");
		if (!pttong(a, m, n))
			fprintf(f2, "Khong co pha tu nao bang tong cac pha tu con lai trong ma tran.\n");
		else
			fprintf(f2, "Phan tu co gia tri bang tong cac pha tu con lai trong ma tran = %d\n", pttong(a, m, n));
		fclose(f2);
	}



}