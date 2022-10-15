//Bai 5.7: Sap xep tang dan
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	float a, b, c, t;
	printf("Nhap 3 so a, b, c: ");
	scanf("%f%f%f", &a, &b, &c);
	if (a > b){
		t = a;
		a = b;
		b = t;
	}
	if (a > c){
		t = a;
		a = c;
		c = t;
	}
	if (b > c){
		t = b;
		b = c;
		c = t;
	}
	printf("Thu tu a, b, c tang dan la: %.1f < %.1f < %.1f\n", a, b, c);

	}
	  