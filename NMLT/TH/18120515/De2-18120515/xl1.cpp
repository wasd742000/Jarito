#include "xl2.h"

long Cau1(char s[], int n){
	long tich = 1;
	for (int i = 0; i < n; i++){
		if ((s[i] * 1) % 2 != 0){
			tich *= ((s[i]- 48));
		}
	}
	return tich;
}

bool Cau2(char s[], int n){
	if (n % 2 == 0){
		if (s[(n / 2) - 1] * 1 != s[(n / 2)] * 1){
			return 0;
		}
		for (int i = 0; i < (n / 2) - 1; i++){
			if (s[i] <= s[i + 1]){
				return 0;
			}
		}
		for (int i = (n / 2) + 1; i < n - 1; i++){
			if (s[i] > s[i + 1]){
				return 0;
			}
		}
		return 1;
	}
	
	else{
		for (int i = 0; i < (n / 2) - 1; i++){
			if (s[i] <= s[i + 1]){
				return 0;
			}
		}
		for (int i = (n / 2) + 1; i < n - 1; i++){
			if (s[i] >= s[i + 1]){
				return 0;
			}
		}
		if (s[(n / 2) - 1] < s[n / 2]){
			return 0;
		}
		if (s[n / 2] > s[(n / 2) + 1]){
			return 0;
		}
		return 1;
	}
}

bool Cau3(char s[], int n){
	if (Cau2(s, n)){
		int sum1 = 0, sum2 = 0;
		if (n % 2 == 0){
			for (int i = 0; i < (n / 2) - 1; i++){
				sum1 += (s[i] * 1 - 48);
			}
			for (int i = n / 2; i < n; i++){
				sum2 += (s[i] * 1 - 48);
			}
			if (ktnt(sum1) == 0 || ktnt(sum2) == 0){
				return 0;
			}
			return 1;
		}
		else{
			for (int i = 0; i < (n / 2) - 1; i++){
				sum1 += (s[i] * 1 - 48);
			}
			for (int i = (n / 2) + 1; i < n; i++){
				sum2 += (s[i] * 1 - 48);
			}
			if (ktnt(sum1) == 0 || ktnt(sum2) == 0){
				return 0;
			}
			return 1;
		}
	}
	else{
		return 0;
	}
}

