#include <stdio.h>
#include "xl1.h"


int main(){
	char s[] = ""; 
	int n = 6;
	printf("Ket qua cau 01: %ld\n", Cau1(s, n));
	printf("Ket qua cau 02: %d\n", Cau2(s, n));
	printf("Ket qua cau 03: %d\n", Cau3(s, n));
	return 0;
}