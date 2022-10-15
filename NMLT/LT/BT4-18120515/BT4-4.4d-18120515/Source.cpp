//Bai 4.4 d
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void main(){
	int  n, s = 0;
	printf("Nhap n = ");
	scanf("%d", &n);
	if (n > 0){
		for (int i = 1; i <= sqrt((float)n); i++) {
				s += i*i;
			}
		printf("S = %d \n", s);
		}
		
	else{
		printf("n phai la so nguyen duong !\n");
		}
	}
	
