#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "xl2.h"
#include "xl1.h"
#define N 100

void menu(int &choice){
	printf("\n\n____MENU___________________\n");
	for (int i = 1; i < 5; i++){
		printf("%d. Bai tap %d.\n", i, i);
	}
	printf("5. Thoat.\n");
	printf("____________________________\nLua chon cua ban:  ");
	scanf("%d", &choice);
}

void b1(){
	int a[N][N], m, n;
	nhapmatran(a, m, n);
	if (ktmtdv(a, m, n)){
		printf("Ma tran la ma tran don vi.\n");
	}
	else{
		printf("Ma tran khong phai la ma tran don vi.\n");
	}
	printf("So lan xuat hien cua so 0 = %d\n", demx(a, m, n, 0));
	printf("Tong cac so duong = %d\nTong cac so am = %d\n", tongduong(a, m, n), tongam(a, m, n));
}

void b2(){
	float a[N][N];
	int m, n;
	nhapmatranr(a, m, n);
	printf("Tong cac so duong = %.2f\n", tongduongr(a, m, n));
	if (ktdongtang(a, m, n)){
		printf("Ma tran ton tai dong ma cac phan tu tang dan trai ---> phai.\n");
	}
	else{
		printf("Ma tran khong ton tai dong nao ma cac pha tu tang dan trai -----> phai.\n");
	}
	vtmaxr(a, m, n);
	if (dxduongcheochinh(a, m, n)){
		printf("Ma tran doi xung qua duong cheo chinh.\n");
	}
	else{
		printf("Ma tran khong doi xung qua duong cheo chinh.\n");
	}
	nguyentomax(a, m, n);
	printf("Tong cac phan tu trong tam giac vuong tren = %.2f\n", tongtamgiactren(a, m, n));
}

void b3(){
	int a[N][N], m, n;
	nhapmatran(a, m, n);
	outb3(a, m, n);
}

void b4(){
	int a[N][N], m, n;
	nhapmatran(a, m, n);
	mangB(a, m, n);
	outb4(a, m, n);
}