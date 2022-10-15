//Bai 5.6: kiem tra tam giac. 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	float a, b, c;
	printf("Nhap 3 canh cua tam giac : ");
	scanf("%f%f%f", &a, &b, &c);
	if ((a + b > c) && (a + c > b) && (b + c > a)){
		if (((a*a+b*b) == (c*c)) || ((a*a+c*c) == (b*b)) || ((b*b+c*c) == (a*a))){
			if (a==b || a==c || b==c){
				printf("Day la tam giac vuong can.\n");
			}
			else{
				printf("Day la tam giac vuong.\n");
			}
		}
		else if (a == b && b == c){
			printf("Day la tam giac deu.\n");
		}
		else if (a == b || a == c || b == c){
			printf("Day la tam giac can.\n");
		}
		else{
			printf("Day la tam giac thuong.\n");
		}
	}
	else{
		printf("Day khong phai la tam giac.\n");
	}
}