#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	int ma, so;
	char kytu;
	printf("Nhap mot ky tu: ");
	scanf("%c", &kytu);
	ma = kytu + 0;
	printf("Ma ASCII tuong ung = %d \n", ma);
	printf("Nhap vao mot so nguyen =  ");
	scanf("%d", &so);
	printf("Ky tu tuong ung la: %c \n", so);
	

}