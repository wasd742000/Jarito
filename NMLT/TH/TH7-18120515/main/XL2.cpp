#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "xl2.h"

// 1
void nhapmatran(int a[][100], int &m, int &n){
	printf("Ma tran m dong n cot.\nNhap m va n: ");
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("Nhap a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

// KT ma tran don vi
bool ktmtdv(int a[][100], int m, int n){
	if (m != n){
		return 0;
	}
	else{
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (i == j){
					if (a[i][j] != 1)return 0;
				}
				else{
					if (a[i][j] != 0)return 0;
				}
			}
		}
		return 1;
	}
}

// dem x trong ma tran
int demx(int a[][100], int m, int n, int x){
	int dem = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == x){
				dem++;
			}
		}
	}
	return dem;
}

int tongduong(int a[][100], int m, int n){
	int tong = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] > 0){
				tong += a[i][j];
			}
		}
	}
	return tong;
}

int tongam(int a[][100], int m, int n){
	int tong = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] < 0){
				tong += a[i][j];
			}
		}
	}
	return tong;
}

// 2
void nhapmatranr(float a[][100], int &m, int &n){
	printf("Ma tran so thuc m dong n cot.\nNhap m va n: ");
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("Nhap a[%d][%d] = ", i, j);
			scanf("%f", &a[i][j]);
		}
	}
}

float tongduongr(float a[][100], int m, int n){
	float tong = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] > 0){
				tong += a[i][j];
			}
		}
	}
	return tong;
}

bool kttang(float a[][100], int m, int n, int dong){
	for (int i = 0; i < m; i++){
		if (a[i][dong] > a[i + 1][dong]){
			return 0;
		}
	}
	return 1;
}

bool ktdongtang(float a[][100], int m, int n){
	for (int i = 0; i < n; i++){
		if (kttang(a, m, n, i)){
			return 1;
		}
	}
	return 0;
}

// Tra ve gia tri max trong ma tran thuc
float maxmtr(float a[][100], int m, int n){
	float max = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] > max){
				max = a[i][j];
			}
		}
	}
	return max;
}

void vtmaxr(float a[][100], int m, int n){
	printf("Vi tri cac gia tri max: \n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == maxmtr(a, m ,n)){
				printf("a[%d][%d] \n", i, j);
			}
		}
	}
}

// KT doi xung qua duong cheo chinh
bool dxduongcheochinh(float a[][100], int m, int n){
	if (m != n){
		return 0;
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (i != j){
				if (a[i][j] != a[j][i]){
					return 0;
				}
			}
		}
	}
	return 1;
}

bool ktnt(float x){
	if (x < 2){
		return 0;
	}
	else if (x == 2){
		return 1;
	}
	else if (x - int(x) != 0){
		return 0;
	}
	else{
		for (int i = 2; i < x; i++){
			if (int(x) % i == 0){
				return 0;
			}
		}
		return 1;
	}
}

void nguyentomax(float a[][100], int m, int n){
	float nt[100];
	int dem = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (ktnt(a[i][j])){
				nt[dem] = a[i][j];
				dem++;
			}
		}
	}
	if (dem == 0){
		printf("Khong co so nguyen to nao trong ma tran.\n");
	}
	else{
		float max = 0;
		for (int i = 0; i < dem; i++){
			if (nt[i] > max){
				max = nt[i];
			}
		}
		printf("So nguyen to lon nhat trong ma tran = %.0f\n", max);
	}
}

float tongtamgiactren(float a[][100], int m, int n){
	float temp[100];
	int dem = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (i <= j){
				temp[dem] = a[i][j];
				dem++;
			}
		}
	}
	float tong = 0;
	for (int i = 0; i < dem; i++){
		tong += temp[i];
	}
	return tong;
}

// 3

void outb3(int a[][100], int m, int n){
	printf("Cac phan tu co gia tri lon nhat dong va gia tri nho nhat cot la: ");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == maxdong(a, m, n, j) && a[i][j] == mincot(a, m, n, i)){
				printf("a[%d][%d] = %d\n", i, j, a[i][j]);
			}
		}
	}
}

int maxdong(int a[][100], int m, int n, int dong){
	int max = 0;
	for (int i = 0; i < m; i++){
		if (a[i][dong] > max){
			max = a[i][dong];
		}
	}
	return max;
}
int mincot(int a[][100], int m, int n, int cot){
	int min = a[cot][0];
	for (int i = 0; i < n; i++){
		if (a[cot][i] < min){
			min = a[cot][i];
		}
	}
	return min;
}

// B4
void mangB(int a[][100], int m, int n){
	int b[100], lb = 0;
	for (int i = 0; i < n; i++){
		b[lb] = tongdong(a, m, n, i);
		lb++;
	}
	printf("Mang b la mang chua tong cac phan tu tung dong mang a:\n");
	for (int i = 0; i < lb; i++){
		printf("b[%d] = %d\n", i, b[i]);
	}
}

int tongdong(int a[][100], int m, int n, int dong){
	int tong = 0;
	for (int i = 0; i < m; i++){
		tong += a[i][dong];
	}
	return tong;
}


void outb4(int a[][100], int m, int n){
	int max = tongdong(a, m, n, 0), min = tongdong(a, m, n, 0), dmax = 0, dmin = 0;
	for (int i = 1; i < n; i++){
		if (tongdong(a, m, n, i) > max){
			max = tongdong(a, m, n, i);
			dmax = i;
		}
		if (tongdong(a, m, n, i) < min){
			min = tongdong(a, m, n, i);
			dmin = i;
		}
	}
	printf("Dong co tong lon nhat la dong j = %d - Max = %d\nDong co tong be nhat la dong j = %d - Min = %d\n", dmax, max, dmin, min);
}