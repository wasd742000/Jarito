#define _CRT_SECURE_NO_WARNINGS
#include "ham7.5.h"
#include <stdio.h>
#include <string.h>
#define N 100
void main(){
	char a[N];
	printf("Nhap chuoi : ");
	gets(a);
	boktdc(a);
	boktgiua(a);
	upcase(a);
	puts(a);
}