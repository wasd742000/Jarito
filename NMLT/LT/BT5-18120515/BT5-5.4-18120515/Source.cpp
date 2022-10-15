//Bai 5.4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n, i = 1, max = 0, min = 2147483647;
	do{
		printf("Nhap so thu %d = ", i);
		scanf("%d",&n);
		i++;
		if (n >= 0){
			//Stop khi n = 0
			if (!n){
				break;
			}
			else{
				if (n > max){
					max = n;
				}
				else if (n < min){
					min = n;
				}
			}
		}
		//Loai so < 0
		else{
			printf("Phai nhap so nguyen duong !\n");
		}
	} while (n!=0);
	printf("So lon nhat = %d\n", max);
	printf("So be nhat = %d\n", min);
}