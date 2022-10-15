#include <stdio.h>
#include "ham7.3.h"
#include <string.h>
#define N 100
void main(){
	char s1[N], s2[N];
	nhap2chuoi(s1, s2);
	int l1 = strlen(s1), l2 = strlen(s2);
	//Thuc hien chen chuoi s1 vao giua s2
	chen1_2(s1, s2);
	for (int i = 0; i < l1 + l2; i++){
		printf("%c", s2[i]);
	}
	printf("\n");
}