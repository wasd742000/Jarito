//Bai 5.9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void main(){
	char so[20];
	printf("Nhap N = ");
	gets(so);
	int ktgiam;
	int dodai = strlen(so);
	//Kiem tra giam dan tu hang don vi
		for (int i = dodai - 1; i >= 0; i--){
			if (so[i]*1 > so[i - 1]*1){
				ktgiam = 1;
			}
			else{
				ktgiam = 0;
				break;
			}
		}
		if (ktgiam){
			printf("Cac chu so giam dan tu hang don vi.\n");
		}
		else{
			printf("Cac chu so khong giam dan tu hang don vi.\n");
		}
	//Kiem tra doi xung
		int ktdx;
		int n = 0;
		for (int x = dodai - 1; x >= (dodai / 2); x--){
			if (so[x] * 1 == so[n] * 1){
				ktdx = 1;
			}
			else{
				ktdx = 0;
				break;
			}
			n++;
		}
		if (ktdx){
			printf("Cac chu so doi xung.\n");
		}
		else{
			printf("Cac chu so khong doi xung.\n");
		}
}