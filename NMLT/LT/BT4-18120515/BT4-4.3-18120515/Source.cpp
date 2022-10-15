//Bai 4.3: tinh ngay trong thang
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int nam, thang, ngay;
	printf("Nhap thang va nam = ");
	scanf("%d%d", &thang, &nam);
	switch (thang){
		case 2:
			if (nam % 10 == 0 && (nam / 10) % 10 == 0){
				if (nam % 400 == 0) ngay = 29;
				else ngay = 28;
			}
			else if (nam % 4 == 0) ngay = 29;
			else ngay = 28;
		break;
		case 1:
		case 3:
		case 5: 
		case 7:
		case 8:
		case 10:
		case 12:
			ngay = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			ngay = 30;
			break;
	}
	printf("Thang %d nam %d co %d ngay.\n", thang, nam, ngay);
}