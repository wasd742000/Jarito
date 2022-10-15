#define _CRT_SECURE_NO_WANINGS
#include <stdio.h>
void main(){
	int chuc, tram, dv, dem = 1, i = 999;
	printf("Chuong trinh tim so nguyen duong co ba chu so thoa chu so hang chuc = hang tram + hang don vi.\n\n");
	while (i >= 100){
		dv = i % 10;
		chuc = (i / 10) % 10;
		tram = ((i / 10) / 10) % 10;
		if (chuc == tram + dv){
			printf("%d: so %d thoa tinh chat.\n",dem, i);
			dem++;
		}
		i--;
	}
}