//Bai 7.1.2
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(){
	int n, ketqua = 0;
	printf("Nhap n = ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		ketqua += i*i;
	}
	printf("S = %d\n ", ketqua);
}