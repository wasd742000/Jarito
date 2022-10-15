#include "ham.h"
#include <stdio.h>
void main(){
	int c;
	do{
		menu(c);
		switch (c){
		case 1:ct1(); break;
		case 2:ct2(); break;
		case 3:ct3(); break;
		case 4:ct4(); break;
		case 5:ct5(); break;
		default:
			printf("Nhap sai !\n");
		}
	} while (c != 6);
}