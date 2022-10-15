#include "xl1.h"

struct phanso{
	int tu;
	int mau;
};


void main(){
	phanso ps1, ps2;
	nhapps(ps1.tu, ps1.mau);
	nhapps(ps2.tu, ps2.mau);
	outb3(ps1.tu, ps1.mau, ps2.tu, ps2.mau);
}