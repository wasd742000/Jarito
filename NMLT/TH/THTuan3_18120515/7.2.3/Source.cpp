//Bai 7.2.3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int y, m, d, x;
	do {
		printf("Nhap ngay sinh : ");
		scanf("%d", &d);
		printf("Nhap thang sinh : ");
		scanf("%d", &m);
		printf("Nhap nam sinh : ");
		scanf("%d", &y);
		if (y > 0 && d > 0 && m > 0){
			switch (m){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (d > 31){
					x = 0;
				}
				else{
					x = 1;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (d > 30){
					x = 0;
				}
				else{
					x = 1;
				}
				break;
			case 2:
				if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)){
					if (d > 29){
						x = 0;
					}
					else{
						x = 1;
					}
				}
				else {
					if (d > 28){
						x = 0;
					}
					else{
						x = 1;
					}
				}
				break;
			default:
				x = 0;
				break;
			}
		}
		else {
			x = 0;
		}
	} while (!x);
	printf("Ngay thang sinh la: %d / %d / %d\n", d, m, y);
}