#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 100
void main(){
	char nd[N], link1[100], link2[100];
	printf("Nhap duong dan file 1: ");
	gets(link1);
	printf("Nhap duong dan file 2: ");
	gets(link2);

	FILE *f2 = fopen(link2, "r");
	if (f2 == NULL)
		printf("Khong mo duoc file 2 !\n");
	else{
		printf("Mo thanh cong file 2 !\n");
		fgets(nd, 99, f2);
		fclose(f2);
	}

	FILE *f1 = fopen(link1, "a");
	if (f1 == NULL)
		printf("Khong mo duoc file 1 !\n");
	else{
		printf("Mo thanh cong file 1 !\n");

		fprintf(f1, "%s", nd);
		fclose(f1);
	}
}