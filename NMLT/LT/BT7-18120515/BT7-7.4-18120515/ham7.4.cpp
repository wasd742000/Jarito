#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "ham7.4.h"
#define N 100

void nhapchuoi(char a[]){
	printf("Nhap chuoi = ");
	gets(a);
}


void demkitu(char a[]){
	char max[N];
	int kt[N];
	int l = strlen(a), imax, u, dem;
	for (int i = 0; i < l; i++){
		kt[i] = 0;                   //Khoi tao mot mang kiem tra phan tu.
	}
	imax = 0;
	u = 0; 
	for (int i = 0; i < l; i++){
		if (kt[i] == 0){
			dem = 1;
			for (int j = i + 1; j < l; j++)
			{
				if (a[i] == a[j])
				{
					kt[j] = 1;
					dem++;
				}
			}
			if (dem > u)
			{
				int v;
				for (v = 0; v <= imax; v++) max[v] = '\0';  
				imax = 0;
				max[imax] = a[i];
				imax++;
				u = dem;
			}
			if (dem == u && max[imax - 1] != a[i])
			{
				max[imax] = a[i];
				imax++;
				u = dem;
			}
		}
	}
	max[imax] = '\0';
	printf("Cac ki tu xuat hien nhieu nhat trong chuoi: \n");
	for (int i = 0; i < imax; i++){
		printf("%c : %d lan.\n", max[i], u);
	}
}

