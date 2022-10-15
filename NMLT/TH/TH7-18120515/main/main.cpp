#include "xl1.h"

void main(){
	int c;
	do{
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
		case 4:
			b4();
			break;
		}
	} while (c != 5);
}