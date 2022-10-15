//Bai 5.9: tinh tien Internet.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void main(){
	float gio1, gio2, tien, d;
	printf("Nhap gio bat dau: ");
	scanf("%f", &gio1);
	printf("Nhap gio ket thuc: ");
	scanf("%f", &gio2);
	d = abs(gio2 - gio1); 
	if (gio1 >= 7 && gio2 <= 17){
		if (d > 6){
			tien = d * 60 * 400 * ((float)90 / 100);
		}
		else{
			tien = d * 60 * 400;
		}
	}
	else if (gio1 >= 18 && gio2 <= 24 ){
		if (d > 4){
			tien = d * 60 * 350 * ((float)88 / 100);
		}
		else{
			tien = d * 60 * 350;
			}
		}
	else if (gio1 >= 1 && gio2 <= 6){
		if (d > 4){
			tien = d * 60 * 300 * ((float)85 / 100);
		}
		else{
			tien = d * 60 * 300;
		}
	}
	printf("So tien internet: %.1f\n", tien);
}