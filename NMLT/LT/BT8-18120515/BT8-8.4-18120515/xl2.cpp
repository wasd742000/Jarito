#include "xl2.h"


void rutgonps(int &tu, int &mau){
	if (tu == mau){
		mau = 1;
		tu = mau;
	}
	else if (tu > mau){
		for (int i = mau; i > 1; i--){
			if (tu % i == 0 && mau % i == 0){
				tu /= i;
				mau /= i;
			}
		}
	}
	else {
		for (int i = tu; i > 1; i--){
			if (tu % i == 0 && mau % i == 0){
				tu /= i;
				mau /= i;
			}
		}
	}
}