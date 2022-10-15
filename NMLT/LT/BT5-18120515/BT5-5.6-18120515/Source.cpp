//Tim UCLN va BCNN
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int a, b, boi = 1, uoc;
	printf("Nhap 2 so nguyen duong a, b: ");
	scanf("%d%d", &a, &b);
	while (boi % a != 0|| boi % b != 0){
		boi++;
	}
	if (a > b){
		uoc = a;
	}
	else{
		uoc = b;
	}
	while (a % uoc != 0 || b % uoc != 0   ){
		uoc--;
	}
	printf("Uoc chung lon nhat = %d\n", uoc);
	printf("Boi chung nho nhat = %d\n", boi);
}