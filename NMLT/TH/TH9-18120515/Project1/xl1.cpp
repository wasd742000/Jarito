#define _CRT_SECURE_NO_WARNINGS
#include "xl1.h"
#include "xl2.h"
#include <stdio.h>
#include <math.h>

//BT 5.1
void nhap(phanso &ps){
	do{
		printf("Nhap tu so va mau so: ");
		scanf("%d%d", &ps.tu, &ps.mau);
	} while (ps.mau == 0);
}

phanso rutgon(phanso ps){
	phanso temp;
	if (ps.tu == ps.mau && ps.tu != 0){
		temp.tu = 1;
		temp.mau = 1;
	}
	else {
		temp.tu = ps.tu / ucln(ps.tu, ps.mau);
		temp.mau = ps.mau / ucln(ps.tu, ps.mau);
	}
	return temp;
}

phanso tong(phanso ps1, phanso ps2){
	phanso ps;
	ps.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
	ps.mau = ps1.mau * ps2.mau;
	return rutgon(ps);
}

phanso hieu(phanso ps1, phanso ps2){
	phanso ps;
	ps.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
	ps.mau = ps1.mau * ps2.mau;
	return rutgon(ps);
}

phanso tich(phanso ps1, phanso ps2){
	phanso ps;
	ps.tu = ps1.tu * ps2.tu;
	ps.mau = ps1.mau * ps2.mau;
	return rutgon(ps);
}

phanso thuong(phanso ps1, phanso ps2){
	phanso ps;
	ps.tu = ps1.tu * ps2.mau;
	ps.mau = ps1.mau * ps2.tu;
	return rutgon(ps);
}

// BT 5.2

void nhap(triangle &t){
	do{
		printf("Nhap diem thu nhat cua tam giac a(x1, y1) = ");
		scanf("%d%d", &t.d1.x, &t.d1.y);
		printf("Nhap diem thu hai cua tam giac b(x2, y2) = ");
		scanf("%d%d", &t.d2.x, &t.d2.y);
		printf("Nhap diem thu ba cua tam giac c(x1, y1) = ");
		scanf("%d%d", &t.d3.x, &t.d3.y);
		if (!kttg(t)){
			printf("Cac diem khong tao thanh tam giac !\n");
		}
	} while(!kttg(t));
}

// vector ab
coordinate vector(coordinate a, coordinate b){
	coordinate ab;
	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	return ab;
}

//lenght vector
float lenvector(coordinate a, coordinate b){
	float l = sqrt( float((vector(a, b).x) * (vector(a, b).x) + (vector(a, b).y) * (vector(a, b).y) ));
	return l;
}

bool kttg(triangle t){
	coordinate ab = vector(t.d1, t.d2);
	coordinate ac = vector(t. d1, t.d3);
	bool kt = (float(ab.x) / ac.x) == (float(ab.y) / ac.y);
	if (kt){
		return 0;
	}
	return 1;
}

float area(triangle t){
	coordinate ab = vector(t.d1, t.d2);
	coordinate ac = vector(t.d1, t.d3);
	float s = float(abs(ab.x * ac.y - ab.y * ac.x)) / 2;
	return s;
}

float perimeter(triangle t){
	float p = lenvector(t.d1, t.d2) + lenvector(t.d1, t.d3) + lenvector(t.d2, t.d3);
	return p;
}

//BT 5.3
bool ktngay(NGAY d){
	if (d.ngay < 1 || d.thang < 1 || d.nam < 1){
		return 0;
	}
	switch (d.thang){
	case 1: 
	case 3:
	case 5: 
	case 7:
	case 8:
	case 10:
	case 12:
		if (d.ngay > 31){
			return 0;
		}
		break;
	case 4:
	case 6: 
	case 9:
	case 11:
		if (d.ngay > 30){
			return 0;
		}
		break;
	case 2:
		if (namnhuan(d)){
			if (d.ngay > 29){ return 0; }
		}
		else {
			if (d.ngay > 28){ return 0; }
		}
		break;
	default :
		return 0;
		break;
	}
	return 1;
}
void nhap(NGAY &d){
	do {
		printf("Nhap ngay, thang, nam: ");
		scanf("%d%d%d", &d.ngay, &d.thang, &d.nam);
		if (!ktngay(d)){
			printf("Ngay khong hop le !\n");
		}
	}while (!ktngay(d));
}

//Tinh khoang cach theo ngay/thang/nam (thang = 30 ngay, nam = 365 ngay )
span khoangcach(NGAY d1, NGAY d2){
	span temp;
	temp.ngay = fabs(float(d1.ngay + d1.thang * 30 + d1.nam * 365 - (d2.ngay + d2.thang * 30 + d2.nam * 365)));
	temp.thang = fabs(float(d1.ngay) / 30 + d1.thang + d1.nam * 12 - (float(d2.ngay) / 30 + d2.thang + d2.nam * 12));
	temp.nam = fabs(float(d1.ngay) / 365 + float(d1.thang) / 12 + d1.nam - (float(d2.ngay) / 365 + d2.thang / 12 + d2.nam));
	return temp;
}

bool namnhuan(NGAY d){
	if (d.nam % 100 == 0){
		if (d.nam % 400 == 0){
			return 1;
		}
		return 0;
	}
	else{
		if (d.nam % 4 == 0){
			return 1;
		}
		return 0;
	}
}

NGAY homqua(NGAY d){
	NGAY temp;
	if (d.ngay == 1){
		switch (d.thang){
		case 2:
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:
			temp.ngay = 31;
			temp.thang = d.thang - 1;
			temp.nam = d.nam;
			break;
		case 1:
			temp.ngay = 31;
			temp.thang = 12;
			temp.nam = d.nam - 1;
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			temp.ngay = 30;
			temp.thang = d.thang - 1;
			temp.nam = d.nam;
			break;
		case 3: 
			temp.nam = d.nam;
			temp.thang = 2;
			if (namnhuan(d)){
				temp.ngay = 29;
			}
			else{
				temp.ngay = 28;
			}
			break;
		}
	}
	else{
		temp.ngay = d.ngay - 1;
		temp.thang = d.thang;
		temp.nam = d.nam;
	}
	return temp;
}

NGAY homsau(NGAY d){
	NGAY temp;
	switch (d.thang){
	case 4:
	case 6:
	case 9:
	case 11:
		if (d.ngay == 30){
			temp.ngay = 1;
			temp.thang = d.thang + 1;	
			temp.nam = d.nam;
		}
		else{
			temp.ngay = d.ngay + 1;	
			temp.thang = d.thang;
			temp.nam = d.nam;
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (d.ngay == 31){
			temp.ngay = 1;
			if (d.thang == 12){
				temp.nam = d.nam + 1;
				temp.thang = 1;
			}
			else{
				temp.thang = d.thang + 1;				
				temp.nam = d.nam;
			}
		}
		else{
			temp.ngay = d.ngay + 1;
			temp.thang = d.thang;
			temp.nam = d.nam;
		}
		break;
	case 2:
		temp.ngay = d.ngay + 1;
		temp.thang = d.thang;
		if ((namnhuan(d) && d.ngay == 29) || !namnhuan(d) && d.ngay == 28){
			temp.ngay = 1;
			temp.thang = 3;
		}
		temp.nam = d.nam;
		break;
	}
	return temp;
}


NGAY truock(NGAY d, int k){
	while (k > 0){
		d.ngay --;
		k--;
		if (d.ngay == 0){
			switch (d.thang){
			case 1 : 
				k--;
				d.ngay = 31;
				d.thang = 12;
				d.nam --;
				break;
			case 2: 
			case 4:
			case 6:
			case 8:
			case 9:
			case 11:
				k--;
				d.ngay = 31;
				d.thang --;
				break;
			case 3:
				k--;
				d.thang = 2;
				if (namnhuan(d)) d.ngay = 29;
				else d.ngay = 28;
				break;
			case 5:
			case 7:
			case 10:
			case 12:
				k--;
				d.ngay = 30;
				d.thang--;
				break;
			}
		}
	}
	return d;
}


NGAY sauk(NGAY d, int k){
	while (k > 0){
		switch (d.thang){
		case 1:
		case 3:
		case 5:
		case 7: 
		case 8:
		case 10:
			if (d.ngay == 31){
				d.ngay = 1;
				d.thang++;
				k--;
			}
			else{
				d.ngay++;
				k--;
			}
			break;
		case 2: 
			if (namnhuan(d)){
				if (d.ngay == 29){
					d.ngay = 1;
					d.thang++;
					k--;
				}
				else{
					d.ngay++;
					k--;
				}
			}
			else {
				if (d.ngay == 28){
					d.ngay = 1;
					d.thang++;
					k--;
				}
				else{
					d.ngay++;
					k--;
				}
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (d.ngay == 30){
				d.ngay = 1;
				d.thang++;
				k--;
			}
			else{
				d.ngay++;
				k--;
			}
			break;
		case 12:
			if (d.ngay == 31){
				d.ngay = 1;
				d.thang = 1;
				d.nam++;
				k--;
			}
			else{
				d.ngay++;
				k--;
			}
			break;
		}
	}
	return d;
}










