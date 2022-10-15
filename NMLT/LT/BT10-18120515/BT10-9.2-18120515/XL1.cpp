


int tongconlai(int a[][100], int m, int n, int dong, int cot);

int pttong(int a[][100], int m, int n){
	int pt = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == tongconlai(a, m, n, i, j)){
				pt = a[i][j];
			}
		}
	}
	return pt;
}

int tongconlai(int a[][100], int m, int n, int dong, int cot){
	int tong = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (i != cot || j != dong){
				tong += a[i][j];
			}
		}
	}
	return tong;
}