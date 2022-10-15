#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "xl1.h"


void nhap(char ten[], char ngaysinh[], bool &gioitinh, float &diemvan, float &diemtoan){
	
	printf("Nhap ho ten hoc sinh : ");
	gets(ten); 
	printf("Nhap ngay sinh: ");
	gets(ngaysinh);
	printf("Nhap gioi tinh (nam: 1, nu: 0) = ");
	scanf("%b", &gioitinh);
	printf("Nhap diem mon van va mon toan = ");
	scanf("%d%d", &diemvan, &diemtoan);	
}



