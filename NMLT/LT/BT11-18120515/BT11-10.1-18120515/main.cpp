#include <stdio.h>
#include "xl1.h"
#include <stdlib.h>

void main(){
	int n;
	nhapn(n);
	hocsinh *hs = (hocsinh *)malloc(n * sizeof(hocsinh));
	nhap(hs, n);
	sapxep(hs, n);
	for (int i = 0; i < n; i++){
		printf("Hoc sinh %d:\nTen: %s---Diem trung binh = %.2f\n", i + 1, hs[i].ten, diemtb(hs[i]));
	}
	xuat(hs, n);
	free(hs);
}