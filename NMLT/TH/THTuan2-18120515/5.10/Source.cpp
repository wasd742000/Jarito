//Baitap 5.10: tinh tien thue phong
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	char phong;
	int ngay;
	float tien;
	printf("Chon loai phong (A, B, C): ");
	scanf(" %c", &phong);
	printf("Nhap so ngay thue: " );
	scanf("%d", &ngay);
	
	if (phong*1 == 65 || phong*1 == 97){
		if (ngay > 12){
			tien = ngay * 250000 * (90.0 / 100);
		}
		else{
			tien = ngay * 250000;
		}
	}
	else if (phong*1 == 66 || phong*1 == 98 ){
		if (ngay > 12){
			tien = ngay * 200000 * (92.0 / 100);
		}
		else{
			tien = ngay * 200000;
		}
	}
	else if (phong*1 == 67 || phong*1 == 99){
		if (ngay > 12){
			tien = ngay * 150000 * (92.0/100);
		}
		else{
			tien = ngay * 150000;
		}
	}
	printf("So tien thue phong =  %.1f d\n", tien);

}