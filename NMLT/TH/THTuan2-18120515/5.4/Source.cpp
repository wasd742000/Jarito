//Bai 5.4: tim max trong 3 so.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	float a, b, c, max;
	printf("Nhap ba so a, b, c: ");
	scanf("%f%f%f", &a, &b, &c);
	if (a > b){
		if (a > c){
			max = a;
		}
		else{
			max = c;
		}
	}
	else{
		if (b > c){
			max = b;
		}
		else{
			max = c;
		}
	}
	printf("So lon nhat = %.1f\n", max);
}