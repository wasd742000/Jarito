//Bai 5.11: xac dinh mua .
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int thang;
	printf("Nhap thang: ");
	scanf("%d", &thang);
	switch (thang){
		case 1:
		case 2:
		case 3: 
			printf("Thang %d la mua xuan.\n", thang); break;
		case 4:
		case 5:
		case 6:
			printf("Thang %d la mua he.\n", thang); break;
		case 7:
		case 8:
		case 9:
			printf("Thang %d la mua thu.\n", thang); break;
		case 10:
		case 11:
		case 12:
			printf("Thang %d la mua dong.\n", thang); break;
		default:
			printf("Thang nhap khong hop le.\n");
	}

}
