#include <string.h>

void encrypt(char ma[], int k){
	int l = strlen(ma);
	for (int i = 0; i < l; i++){
		if (ma[i] != ' '){
			if (int(ma[i]) > 64 && int(ma[i]) < 91){
				ma[i] += k;
				if (int(ma[i]) > 90){
					int lech = ma[i] - 90;
					ma[i] = 64 + lech;
				}
			}
			else if (int(ma[i]) > 96 && int(ma[i]) < 123){
				ma[i] += k;
				if (int(ma[i]) > 122){
					int lech = ma[i] - 122;
					ma[i] = 96 + lech;
				}
			}
		}
	}
}


void decrypt(char ma[], int k){
	int l = strlen(ma);
	for (int i = 0; i < l; i++){
		if (ma[i] != ' '){
			if (int(ma[i]) > 64 && int(ma[i]) < 91){
				ma[i] -= k;
				if (int(ma[i]) < 65){
					int lech = 65 - ma[i];
					ma[i] = 91 - lech;
				}
			}
			else if (int(ma[i]) > 96 && int(ma[i]) < 123){
				ma[i] -= k;
				if (int(ma[i]) < 97){
					int lech = 97 - ma[i];
					ma[i] = 123 - lech;
				}
			}
		}
	}
}