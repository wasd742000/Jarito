#include "xl2.h"


int ucln(int a, int b){
	if (a < 0){
		a *= -1;
	}
	if (b < 0){
		b *= -1;
	}
	if (a == b){
		return a;
	}
	while (a != b){
		if (a > b){
			a -= b;
		}
		else {
			b -= a;
		}
	}
		return a;
}

