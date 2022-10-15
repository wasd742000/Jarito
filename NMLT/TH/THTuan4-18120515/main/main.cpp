#include "ham.h"
#include "btchinh.h"
#include <stdio.h>
void main(){
	int luachon;
	do{
		menu(luachon);
		switch (luachon){
		case 1:{b1(); break; }
		case 2:{b2(); break; }
		case 3:{b3(); break; }
		case 4:{b4(); break; }
		case 5:{b5(); break; }
		case 6:{b6(); break; }
		case 7:{b7(); break; }
		case 8:{b8(); break; }
		case 9:{b9(); break; }
		case 10:{b10(); break; }
		case 11:{b11(); break; }
		default:
			 printf("Nhap sai !\n");
			 break;		
		}
	} while (luachon != 12);
}