//Bai 5.2: Kiem tra chan, le.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int x;
	printf("Nhap so nguyen x = ");
	scanf("%d", &x);
	if (x % 2 == 0){
		printf("x la so chan.\n");
	}
	else{
		printf("x la so le.\n");
	}
}