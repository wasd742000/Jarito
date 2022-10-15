//Bai 5.8: tinh tien taxi.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	float km, tien;
	printf("Nhap quang duong di duoc(Km): ");
	scanf("%f", &km);
	if (km <= 1){
		tien = km * 5000;
	}
	else if (km >= 2 && km <= 5){
		tien = km * 4500;
	}
	else if (km >= 6){
		if (km > 120){ 
			tien = km * 3500 * ((float)90 / 100);
		}
		else{
			tien = km * 3500;
		}
	}
	printf("So tien taxi = %.1f d\n", tien);
}