#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
void main(){
	int n, i = 1, t;
	printf("Nhap n = ");
	scanf("%d",&n);
	while (i <= n){
		if (pow((float)3, i) == n){
			t = 1;
			break;
		}
		else{
			t = 0;
			i++;
		}
	}
	if (t){
		printf("%d co dang 3^k\n", n);
	}
	else{
		printf("%d khong co dang 3^k\n", n);
	}
}