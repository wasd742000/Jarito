#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 100
#include "xl1.h"
void main(){
	
	char mahoa[N], giaima[N];
	int ke, kd;
	FILE *f1 = fopen("vanban.txt", "r");
	if (f1 == NULL)
		printf("Khong mo duoc vanban.txt !\n");
	else{
		printf("Mo thanh cong vanban.txt !\n");
		fgets(mahoa, 99, f1);
		fclose(f1);
	}
	printf("Nhap khoa k de ma hoa van ban : ");
	scanf("%d", &ke);
	encrypt(mahoa, ke);

	FILE *f2 = fopen("mahoa.txt", "w");
	if (f2 == NULL)
		printf("Khong tao duoc mahoa.txt !\n");
	else{
		printf("Tao thanh cong mahoa.txt !\n");
		fprintf(f2, mahoa);
		fclose(f2);
	}

	FILE *f3 = fopen("ma.txt", "r");
	if (f3 == NULL)
		printf("Khong mo duoc ma.txt !\n");
	else{
		printf("Mo thanh cong ma.txt !\n");
		fgets(giaima, 99, f3);
		fclose(f3);
	}
	printf("Nhap khoa k de giai ma : ");
	scanf("%d", &kd);
	decrypt(giaima, kd);

	FILE *f4 = fopen("vanbanduocgiai.txt", "w");
	if (f4 == NULL)
		printf("Khong tao duoc vanbanduocgiai.txt !\n");
	else{
		printf("Tao thanh cong vanbanduocgiai.txt !\n");
		fprintf(f4, giaima);
		fclose(f4);
	}
}