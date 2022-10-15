#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	const int namht = 2018;
	int tuoi, nam; 
	printf("Nhap nam sinh = ");
	scanf("%d", &nam);
	tuoi = namht - nam;
	printf("Ban sinh nam %d, vay ban %d tuoi. \n", nam, tuoi);

}