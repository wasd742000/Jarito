#include "xl1.h"
#include "xl2.h"
#define N 100
#include <stdio.h>

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
		case 5:
			b5();
			break;
		case 6:
			b6();
			break;
		case 7:
			b7();
			break;
		case 8:
			b8();
			break;
		case 9:
			b9();
			break;
		case 10:
			b10();
			break;
		case 11:
			b11();
			break;
		case 12:
			b12();
			break;
		case 13:
			b13();
			break;
		case 14:
			b14();
			break;
		case 15:
			b15();
			break;
		case 16:
			b16();
			break;
		case 17:
			b17();
			break;
		}
	} while (c != 18);
}


