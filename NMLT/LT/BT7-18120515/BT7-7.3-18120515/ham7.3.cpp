#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "ham7.3.h"
#define N 100

void nhap2chuoi(char s1[], char s2[]){
	printf("Nhap chuoi s1 : ");
	gets(s1);
	printf("Nhap chuoi s2 : ");
	gets(s2);
}

void chen1_2(char s1[], char s2[]){
	char temp[N], n = 0;
	int l1 = strlen(s1), l2 = strlen(s2);
	for (int i = 0; i < (l2 / 2); i++){
		temp[n] = s2[i];
		n++;
	}
	for (int i = 0; i < l1; i++){
		temp[n] = s1[i];
		n++;
	}
	for (int i = (l2 / 2) ; i < l2; i++){
		temp[n] = s2[i];
		n++;
	}
	for (int i = 0, j = 0; i < n; i++, j++){
		s2[i] = temp[j];
	}
}


	
