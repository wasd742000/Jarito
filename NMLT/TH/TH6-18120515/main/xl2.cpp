#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "xl2.h"
#define N 100

/* ____DS ham_______:
*Ham input:
- Nhap mang nguyen: nhapmang
- Nhap mang nguyen duong <= 100: nhapmangduong100
- Nhap mang nguyen <= 100: nhapmang100
- Nhap mang thuc: nhapmangr

*Ham bool:
- KT tang dan: kttang
- KT giam dan: ktgiam
- KT so NT: ktnt
- KT tinh chan le (1 chan, 0 le): chanle
- KT so am, duong (1 duong, 0 am): amduong
- KT mot so co cac chu so tang dan tu trai---> phai: chusotang.
- KT so co 3 chu so: bachuso
- KT mang doi xung: ktdx
- Dem so mang B la con cua mang A: demcon


*Ham tinh:
- Tinh TB cac so chan trong mang: tbchan
- Tinh TB cac so le trong mang: tble
- Tinh TB cac so am trong mang: tbam
- Tinh TB cac so duong trong mang: tbduong
- Tinh TB cac so >= k: tbk
- Dem so lan xuat hien cua so nguyen x trong mang: demx
- Dem so lan xuat hien cua so thuc x trong mang(so thuc) = demxr
- Tim phan tu co so lan xuat hien nhieu nhat trong mang(so thuc) = xhmaxr
- Dem phan tu co 3 chu so va cac chu so deu sap tang(exp: 122, 457, 889, ....): dem3tang
- Tim so so nguyen to trong mang la so nguyen to, gan x nhat va < x: timb16
- Tim so lon nhat trong mang: maxarray

*Ham thao tac mang:
- Sap xep mang nguyen tang dan: sxtang
- Sap xep mang nguyen giam dan: sxgiam
- Sap xep mang thuc tang dan: sxtangr
- Sap xep tang dan cac so chan trong mang: sxtangchan
- Sap xep tang dan le dau mang va giam dan chan cuoi mang: sxb9
- Sap xep so le dau mang, so chan cuoi mang, cac so 0 o giua: sxb16
- Xoa x trong mang: xoax
- Chen x vao trong mang ma van giu nguyen thu tu cua mang: chenxtt
- Chen x vao trong mang ma van giu nguyen thu tu cua mang(so thuc): chenxttr
- Chen mang B vao mang A tai vi tri so nguyen p: chenmangp
- Huy n phan tu cua mang bat dau tu vi tri p: huymang
- Gop 2 mang theo thu tu xen ke (mang a la mang duoc gop): xenke
- Xoa cac phan tu giong nhau trong mang: xoatrung
- Copy mang A vao mang B(so thuc): cpr
- Copy mang A vao mang B(so nguyen): cp
- Dem so mang con tang trong A: demcontang
- Tim vi tri mang con trong mang A tang dan va dai nhat: mangcontangmax
*/

int maxarray(int a[], int n){
	int max = 0;
	for (int i = 0; i < n; i++){
		if (a[i] > max){
			max = a[i];
		}
	}
	return max;
}

void cpr(float a[], float b[], int na){
	for (int i = 0; i < na; i++){
		b[i] = a[i];
	}
}

void cp(int a[], int b[], int na){
	for (int i = 0; i < na; i++){
		b[i] = a[i];
	}
}

void sxtang(int a[], int n){
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void sxgiam(int a[], int n){
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] < a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

float tble(int a[], int n){
	int tong = 0, dem = 0;
	float tb;
	for (int i = 0; i < n; i++){
		if (!chanle(a[i])){
			tong += a[i];
			dem++;
		}
	}
	if (dem == 0){
		return 0;
	}
	else{
		tb = float(tong) / dem;
		return tb;
	}
}
bool amduong(int n){
	// 1 la duong, 0 la am
	if (n > 0){
		return 1;
	}
	else{
		return 0;
	}
}

bool chanle(int n){
	// 1 la chan, 0 la le
	if ((n % 2) == 0){
		return 1;
	}
	else{
		return 0;
	}
}


bool ktnt(int n){
	if (n == 2){
		return 1;
	}
	else if (n < 2){
		return 0;
	}
	else {
		for (int i = 2; i < n; i++){
			if (n % i == 0){
				return 0;
			}
		}
		return 1;
	}
}

// B1
void nhapmang(int a[], int &n){
	printf("Nhap so phan tu cua mang = ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatb1(int a[], int n){
	int max = 0, min = a[0];
	for (int i = 0; i < n; i++){
		if (chanle(a[i])){
			if (a[i] > max){
				max = a[i];
			}
		}
		else{
			if (a[i] < min){
				min = a[i];
			}
		}
	}
	printf("So chan lon nhat = %d.\nSo le nho nhat = %d.", max, min);
}

// B2

void nhapmangduong100(int a[], int &n){
	do{
		printf("Nhap so phan tu cua mang nguyen duong (1 ---> 100) = ");
		scanf("%d", &n);
		if (n > 100 || n < 1){
			printf("SAI ! Nhap lai.\n");
		}
	} while (n > 100 || n < 1);
	for (int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

float tbchan(int a[], int n){
	int tong = 0, dem = 0;
	float tb;
	for (int i = 0; i < n; i++){
		if (chanle(a[i])){
			tong += a[i];
			dem++;
		}
	}

	if (dem != 0){
		tb = (float(tong) / dem);
		return tb;
	}
	else{
		return 0;
	}
}

// B3

void nhapmang100(int a[], int &n){
	do{
		printf("So phan tu cua mang (n <= 100) = ");
		scanf("%d", &n);
		if (n > 100){
			printf("SAI! Nhap lai.\n");
		}
	} while (n > 100);
	for (int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

float tbduong(int a[], int n){
	int tong = 0, dem = 0;
	float tb;
	for (int i = 0; i < n; i++){
		if (amduong(a[i])){
			tong += a[i];
			dem++;
		}
	}
	if (dem == 0){
		return 0;
	}
	else{
		tb = float(tong) / dem;
		return tb;
	}
}

float tbam(int a[], int n){
	int tong = 0, dem = 0;
	float tb;
	for (int i = 0; i < n; i++){
		if (!amduong(a[i])){
			tong += a[i];
			dem++;
		}
	}
	if (dem == 0){
		return 0;
	}
	else{
		tb = float(tong) / dem;
		return tb;
	}
}

void sxtangchan(int a[], int n){
	// Loc mang so chan
	int mchan[N], dem = 0;
	for (int i = 0; i < n; i++){
		if (chanle(a[i])){
			mchan[dem] = a[i];
			dem++;
		}
	}
	// Sap xep tang dan
	for (int i = 0; i < dem; i++){
		for (int j = i + 1; j < dem; j++){
			if (mchan[i] > mchan[j]){
				int temp = mchan[j];
				mchan[j] = mchan[i];
				mchan[i] = temp;
			}
		}
	}
	printf("\nSap xep so chan tang dan: \n");
	for (int i = 0; i < dem; i++){
		printf(" %d ", mchan[i]);
		printf("\n");
	}
}



// B4
bool kttang(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		if (a[i] > a[i + 1]){
			return 0;
		}
	}
	return 1;
}

bool ktgiam(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		if (a[i] < a[i + 1]){
			return 0;
		}
	}
	return 1;
}

void kttanggiam(int a[], int n){
	if (kttang(a, n)){
		printf("Mang tang dan.\n");
	}
	else if (ktgiam(a, n)){
		printf("Mang giam dan.\n");
	}
	else{
		printf("Mang khong tang khong giam.\n");
	}
}

// B5


int demx(int a[], int n, int x){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == x){
			dem++;
		}
	}
	return dem;
}

void xoax(int a[], int n, int x){
	for (int i = 0; i < n - 1; i++){
		if (a[i] == x){
			for (int j = i; j <= n - i; j++){
				a[i] = a[i + 1];
			}
		}
	}
}

//B6

void chenxtt(int a[], int &n, int x){
	for (int i = 0; i < n - 1; i++){
		if (x >= a[i] && x <= a[i + 1]){
			for (int j = n; j > i + 1; j--){
				a[j] = a[j - 1];
			}
			a[i + 1] = x;
			n++;
			break;
		}
	}
}

// B7



// B8

float tbk(int a[], int n, int k){
	int tong = 0, dem = 0;
	float tb;
	for (int i = 0; i < n; i++){
		if (a[i] >= k){
			tong += a[i];
			dem++;
		}
	}
	tb = float(tong) / dem;
	return tb;
}

// B9
void sxb9(int a[], int n){
	int chan[N], le[N], no = 0, ne = 0;
	for (int i = 0; i < n; i++){
		if (chanle(a[i])){
			chan[ne] = a[i];
			ne++;
		}
		else{
			le[no] = a[i];
			no++;
		}
	}
	sxtang(le, no);
	sxgiam(chan, ne);
	for (int i = 0; i < no; i++){
		a[i] = le[i];
	}
	for (int i = no, j = 0; i < n, j < ne; i++, j++){
		a[i] = chan[j];
	}
}

// B10

void huymang(int a[], int &n, int p, int k){
	for (int i = 0; i < n - 1; i++){
		if (a[i] == p){
			for (int j = i + k, t = i; j < n, t < n - k; j++){
				a[t] = a[j];
				t++;
			}
		}
	}
	n -= k;
}

// B11

void chenmangp(int a[], int b[], int &na, int nb, int p){
	for (int i = 0; i < na; i++){
		if (a[i] == p){
			for (int j = nb, dem = i + 1; dem < na; j++, dem++){
				b[j] = a[dem];
			}
			for (int j = i + 1, dem = 0; j < (na + nb); dem++, j++){
				a[j] = b[dem];
			}
		}
	}
	na += nb;
}

// B12

void xenke(int a[], int b[], int &na, int nb){
	int temp[N], dema = 0, demb = 0;
	for (int i = 0; i < (na + nb); i++){
		if (chanle(i)){
			temp[i] = a[dema];
			dema++;
		}
		else{
			temp[i] = b[demb];
			demb++;
		}
		if (dema == na || demb == nb){
			if (na > nb){
				temp[i + 1] = a[dema];

			}
			else if (nb > na){
				temp[i + 1] = b[demb];

			}
			break;
		}
	}
	if (na > nb){
		for (int i = 2 * nb; i < na + nb; i++){
			temp[i] = a[dema];
			dema++;
		}
	}
	else if (nb > na){
		for (int i = 2 * na; i < na + nb; i++){
			temp[i] = b[demb];
			demb++;
		}
	}
	for (int i = 0; i < (na + nb); i++){
		a[i] = temp[i];
	}
	na += nb;
}

void xoatrung(int a[], int &n){
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] == a[j]){
				for (int t = j; t < n - 1; t++){
					a[t] = a[t + 1];
				}
				n--;
			}
		}
	}
}

//B13

int demcontang(int a[], int n){
	int l = 1, dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] <= a[i + 1]){
			l++;
		}
		else {
			if (l > 1){
				dem++;
			}
			l = 1;
		}
	}
	return dem;
}

void mangcontangmax(int a[], int n, int &vt, int &l){
	int temp = 1, tempvt;
	for (int i = 0; i < n; i++){
		if (a[i] <= a[i + 1]){
			if (temp == 1){
				tempvt = i;
			}
			temp++;
		}
		else{
			if (temp > l){
				vt = tempvt;
				l = temp;
			}
			temp = 1;
		}
	}
}

// B14
bool ktdx(int a[], int n){
	int temp[N];
	for (int i = n - 1, dem = 0; i > 0; dem++, i--){
		temp[dem] = a[i];
	}
	for (int i = 0; i < n; i++){
		if (a[i] != temp[i]){
			return 0;
		}
		return 1;
	}
}

int demcon(int a[], int b[], int na, int nb){
	bool flag = 1;
	int dem = 0;
	if (nb > na){
		return 0;
	}
	else{
		for (int i = 0; i < na; i++){
			if (b[0] == a[i]){
				int temp = i;
				for (int i = 0; i < nb; i++){
					if (b[i] != a[temp]){
						flag = 0;
						break;
					}
					temp++;
				}
				if (flag){
					dem++;
				}
			}
		}
	}
	return dem;
}

// B15

void nhapmangr(float a[], int &n){
	printf("Nhap so phan tu cua mang = ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%f", &a[i]);
	}
}

void sxtangr(float a[], int n){
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				float temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int demxr(float a[], int n, float x){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == x){
			dem++;
		}
	}
	return dem;
}


float xhmaxr(float a[], int n){
	int max = 0;
	float x;
	for (int i = 0; i < n; i++){
		if (demxr(a, n, a[i]) > max){
			max = demxr(a, n, a[i]);
			x = a[i];
		}
	}
	return x;
}

void invtxh(float a[], int n, float x){
	printf("Vi tri xuat hien cua %.3f la: ", x);
	for (int i = 0; i < n; i++){
		if (a[i] == x){
			printf(" a[%d] ", i);
		}
	}
	printf("\n\n");
}

void chenxttr(float a[], int &n, float x){
	for (int i = 0; i < n - 1; i++){
		if (x >= a[i] && x <= a[i + 1]){
			for (int j = n; j > i + 1; j--){
				a[j] = a[j - 1];
			}
			a[i + 1] = x;
			n++;
			break;
		}
	}
}

// B16

void sxb16(int a[], int n){
	int chan[N], le[N], no = 0, ne = 0, dem0 = 0;
	for (int i = 0; i < n; i++){
		if (a[i] == 0){
			dem0++;
		}
	}
	for (int i = 0; i < n; i++){
		if (chanle(a[i]) && (a[i] != 0)){
			chan[ne] = a[i];
			ne++;
		}
		else if (!chanle(a[i])){
			le[no] = a[i];
			no++;
		}
	}
	for (int i = 0; i < no; i++){
		a[i] = le[i];
	}
	for (int i = no + dem0, j = 0; j < ne; i++, j++){
		a[i] = chan[j];
	}
	for (int i = no; i < no + dem0; i++){
		a[i] = 0;
	}
}

int timb16(int a[], int n, int x){
	int temp[N], dem = 0;
	for (int i = 0; i < n; i++){
		if (ktnt(a[i]) && a[i] < x){
			temp[dem] = a[i];
			dem++;
		}
	}
	return maxarray(temp, dem);
}

// B17

bool chusotang(int n){
	while (n >= 10){
		if ((n % 10) < ((n / 10) % 10)){
			return 0;
		}
		else{
			n /= 10;
		}
	}
	return 1;
}

bool bachuso(int n){
	if (n >= 100 && n <= 999){
		return 1;
	}
	return 0;
}

int dem3tang(int a[], int n){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if (bachuso(a[i]) && chusotang(a[i])){
			dem++;
		}
	}
	return dem;
}






