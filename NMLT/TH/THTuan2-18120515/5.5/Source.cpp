//Bai 5.5: Giai pt ax+b=0.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int a, b;
	float x;
	printf("PT ax +b = 0 \nNhap a, b: ");
	scanf("%d%d", &a, &b);
	if (a == 0 && b == 0){
		printf("PT luon dung.\n");
	}
	else if (a == 0 && b != 0){
		printf("PT vo nghiem.\n");
	}
	else{
		x = (float)(-b) / a;
		printf("PT co nghiem x = %.1f\n", x);
	}
}