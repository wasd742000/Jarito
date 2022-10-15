//Bai 5.3: Tinh thuong.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	float a, b, thuong;
	printf("Nhap 2 so a, b : ");
	scanf("%f%f", &a, &b);
	if (b != 0){
		thuong = a / b;
		printf("Thuong a/b = %.1f\n", thuong);
	}
	else{
		printf("Khong tinh duoc thuong do mau bang 0.\n");
	}
}


