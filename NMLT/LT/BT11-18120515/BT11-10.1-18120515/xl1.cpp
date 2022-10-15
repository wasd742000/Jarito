#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "xl1.h"


void nhapn(int &n){
	FILE *in = fopen("input.txt", "r");
	if (in == NULL){
		printf("Can't open \"input.txt\"\n");
	}
	else {
		printf("Open \"input.txt\" sucessfullly.\n");
		fscanf(in, "%d", &n);
		fclose(in);
	}
}

void nhap(hocsinh *hs, int &n){
	FILE *in = fopen("input.txt", "r");
	if (in == NULL){
		printf("Can't open \"input.txt\"\n");
	}
	else {
		printf("Open \"input.txt\" sucessfullly.\n");
		fscanf(in, "%d", &n);
		for (int i = 0; i < n; i++){
			fflush(stdin);
			fscanf(in, "%s %f %f", hs[i].ten, &hs[i].van, &hs[i].toan);
		}
		fclose(in);
	}
}


float diemtb(hocsinh hs){
	return (hs.van + hs.toan) / 2;
}

void sapxep(hocsinh *hs, int n){
	hocsinh temp;
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (diemtb(hs[i]) < diemtb(hs[j])){
				temp = hs[i];
				hs[i] = hs[j];
				hs[j] = temp;
			}
		}
	}
}


void xuat(hocsinh *hs, int n){
	FILE *out = fopen("output.txt", "w");
	if (out == NULL){
		printf("Can't create \"output.txt\"\n");
	}
	else {
		printf("Create \"output.txt\" sucessfullly.\n");
		fprintf(out, "Danh sach hoc sinh gioi thu tu giam dan:\n");
		for (int i = 0; i < n; i++){
			if (diemtb(hs[i]) >= 8){
				fprintf(out, "Hoc sinh %d:\nTen: %s---Diem trung binh = %.2f\n", i + 1, hs[i].ten, diemtb(hs[i]));
			}
		}
		fclose(out);
	}
}

