//Bai 5.13: kiem tra ngay, thang. 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int d, m, nday, nextday, preday;
	printf("Nam 2018.\nNhap ngay hien tai : ");
	scanf("%d" , &d);
	printf("Nhap thang hien tai: "); 
	scanf("%d", &m);
	switch (m){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d <= 31 && d >= 1){
				nday = 31;
				nextday = d + 1;
				preday = d - 1;
				if (d == 31){
					nextday = 1;
				}
				else if (d == 1){
					preday = 31;
				}
				printf("Thang co %d ngay.\nNgay hom sau la ngay : %d .\nNgay hom truoc la ngay : %d .\n", nday, nextday, preday);
			}
			else{
				printf("Ngay, thang khong hop le !\n");
			}
			break;
		case 4:
		case 6: 
		case 9:
		case 11:
			if (d <= 30 && d>=1){
				nday = 30;
				nextday = d + 1;
				preday = d - 1;
				if (d == 30){
					nextday = 1;
				}
				else if (d == 1){ 
					preday = 30;
				}
				printf("Thang co %d ngay.\nNgay hom sau la ngay : %d .\nNgay hom truoc la ngay : %d .\n", nday, nextday, preday);
			}
			else{
				printf("Ngay, thang khong hop le !\n");
			}
			break;
		case 2: 
			if (d <= 28 && d >= 1){
				nday = 28;
				nextday = d + 1;
				preday = d - 1;
				if (d == 28){
					nextday = 1;
				}
				else if (d == 1){
					preday = 28;
				}
				printf("Thang co %d ngay.\nNgay hom sau la ngay : %d .\nNgay hom truoc la ngay : %d .\n", nday, nextday, preday);
			}
			else{
				printf("Ngay, thang khong hop le !\n");
				}
			break;
		default:
			printf("Thang khong hop le ! \n"); break;
	}
}