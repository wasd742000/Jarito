//Bai 5.12: nhap nam duong lich.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int nam;
	printf("Nhap nam duong lich (tu 1975 tro di): ");
	scanf("%d", &nam);
	if (nam >= 1975){
		if ((nam % 4) == 0){
			printf("Nam %d co to chuc Olympic va Euro.\n", nam);
		}
		else if (nam % 2 == 0 ){
			printf("Nam %d co to chuc World Cup\n", nam);
		}
		else if (nam % 2 != 0){
			printf("Nam %d co to chuc SEA Games\n", nam);
		}
	}
	else{
		printf("Phai nhap nam tu 1975.\n");
	}
}