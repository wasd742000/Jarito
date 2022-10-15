//Bai 5.7: Doc so dien thoai
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void main(){
	char sdt[11];
	printf("So dien thoai: ");
	gets(sdt);
	if (sdt[0]*1 == 48 || strlen(sdt) > 10){
		printf("So dien thoai sai !\n");
	}
	else{
		printf("Cach doc: ");
		for (int i = 0; i < strlen(sdt); i++){
			switch (sdt[i]*1){
				case 48: 
					printf(" khong "); break;
				case 49:
					printf(" mot "); break;
				case 50:
					printf(" hai "); break;
				case 51:
					printf(" ba "); break;
				case 52:
					printf(" bon "); break;
				case 53:
					printf(" nam "); break;
				case 54:
					printf(" sau "); break;
				case 55:
					printf(" bay "); break;
				case 56:
					printf(" tam "); break;
				case 57:
					printf(" chin "); break;

			}
		}
		printf("\n");
	}
}