#include "xl1.h"

struct donthuc {
	int a;
	int n;
};

void main(){
	donthuc dt1, dt2;
	nhap(dt1.a, dt1.n);
	nhap(dt2.a, dt2.n);
	outb4(dt1.a, dt1.n, dt2.a, dt2.n);
}