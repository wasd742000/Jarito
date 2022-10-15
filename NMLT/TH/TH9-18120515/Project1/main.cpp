#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "xl1.h"

void menu(int &choice){
	for (int i = 1; i < 4; i++){
		printf("%d. Bai tap %d.\n", i, i);
	}
	printf("4. Thoat.\n");
	printf("______________________\nChon bai tap: ");
	scanf("%d", &choice);
}



void b1(){
	phanso ps1, ps2;
	nhap(ps1);
	nhap(ps2);
	printf("Tong 2 phan so = %d/%d\n", tong(ps1, ps2).tu, tong(ps1, ps2).mau);
	printf("Hieu 2 phan so = %d/%d\n", hieu(ps1, ps2).tu, hieu(ps1, ps2).mau);
	printf("Tich 2 phan so = %d/%d\n", tich(ps1, ps2).tu, tich(ps1, ps2).mau);
	printf("Thuong 2 phan so = %d/%d\n", thuong(ps1, ps2).tu, thuong(ps1, ps2).mau);
	printf("Rut gon hai phan so : %d/%d va %d/%d\n", rutgon(ps1).tu, rutgon(ps1).mau, rutgon(ps2).tu, rutgon(ps2).mau);
}
void b2(){
	triangle t;
	nhap(t);
	printf("Dien tich tam giac = %.3f\n", area(t));
	printf("Chu vi tam giac = %.3f\n", perimeter(t));
}

void b3(){
	NGAY d1, d2;
	int k;
	nhap(d1);
	nhap(d2);
	printf("Khoang cach giua 2 ngay = %.3f ngay/ %.3f thang/ %.3f nam.\n", khoangcach(d1, d2).ngay, khoangcach(d1, d2).thang, khoangcach(d1, d2).nam);
	printf("Ngay hom sau cua 2 ngay : %d/%d/%d va  %d/%d/%d\n", homsau(d1).ngay, homsau(d1).thang, homsau(d1).nam, homsau(d2).ngay, homsau(d2).thang, homsau(d2).nam);
	printf("Ngay hom truoc cua 2 ngay: %d/%d/%d va %d/%d/%d\n", homqua(d1).ngay, homqua(d1).thang, homqua(d1).nam, homqua(d2).ngay, homqua(d2).thang, homqua(d2).nam);
	printf("Nhap so ngay k = ");
	scanf("%d", &k);
	printf("2 ngay sau %d ngay : %d/%d/%d va %d/%d/%d\n", k, sauk(d1, k).ngay, sauk(d1, k).thang, sauk(d1, k).nam, sauk(d2, k).ngay, sauk(d2, k).thang, sauk(d2, k).nam);
	printf("2 ngay truoc %d ngay: %d/%d/%d va %d/%d/%d\n", k, truock(d1, k).ngay, truock(d1, k).thang, truock(d1, k).nam, truock(d2, k).ngay, truock(d2, k).thang, truock(d2, k).nam);

}

void main(){
	int c;
	do {
		menu(c);
		switch (c){
		case 1:
			b1();
			break;
		case 2:
			b2();
			break;
		case 3:
			b3();
			break; 
		}
	} while (c != 4);
}