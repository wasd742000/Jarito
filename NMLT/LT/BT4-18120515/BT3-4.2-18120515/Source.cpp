//Bai 4.2: giai phuong trinh bac 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void main(){
	float a, b, c, delta, x, y;

	printf("Giai phuong trinh bac hai \nNhap he so a, b, c :");
	scanf("%f%f%f", &a, &b, &c);
	delta = pow(b, 2) - (4 * a * c);
	if (a == 0){
		x = -c / b;
		printf("Phuong trinh co duy nhat 1 nghiem x = %.1f\n ", x);
	}
	else{
		if (delta < 0){
			printf("Phuong trinh vo nghiem ! \n");
		}
		else if (delta == 0){
			x = -b / (2 * a);
			printf("Nghiem kep = %.1f\n", x);
		}
		else if (delta > 0){
			x = (-b - sqrt(delta)) / (2 * a);
			y = (-b + sqrt(delta)) / (2 * a);
			printf("Nghiem 1 = %.1f\nNghiem 2 = %.1f\n", x, y);
		}
	}
}