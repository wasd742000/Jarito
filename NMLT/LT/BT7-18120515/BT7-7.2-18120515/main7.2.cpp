#include "ham7.2.h"
#include <stdio.h>
#define N 100
void main(){
	int a[N], n;
	nhapmang(a, n);
	bool x = kttangdan(a, n), y = ktdx(a, n), z = ktcsc(a, n);
	xuatkt(x, y, z);
}