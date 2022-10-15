#include <string.h>
void upcase(char a[]){
	if (a[0] != ' '){
		a[0] -= 32;
	}
	for (int i = 0; i < strlen(a) - 1; i++){
		if (a[i] == ' ' && a[i + 1] != ' '){
			a[i + 1] = a[i + 1] - 32;
		}
	}
}

void boktgiua(char a[]){
	int dem = 0;
	for (int i = 0; i < strlen(a) - 1; i++){
		while( a[i] == ' ' && a[i + 1] == ' '){
			dem += 1;
			for (int j = i + 1; j < strlen(a) - 1; j++){
				a[j] = a[j + 1];
			}
		}
	}
	a[strlen(a) - dem] = '\0';
}

void boktdc(char a[]){
	int dem = 0;
	while (a[0] == ' '){
		for (int i = 0; i < strlen(a) - 1; i++){
			a[i] = a[i + 1];
		}
		dem += 1;
	}
	while (a[strlen(a) - 1 - dem] == ' '){
		a[strlen(a) - 1] = 'x';
		dem += 1;
	}

	a[strlen(a) - dem] = '\0';

	
}