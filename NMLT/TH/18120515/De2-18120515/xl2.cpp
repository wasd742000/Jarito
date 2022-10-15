// KT so nguyen to
bool ktnt(int n){
	if (n < 2){
		return 0;
	}
	if (n == 2){
		return 1;
	}
	for (int i = 2; i < n; i++){
		if (n % i == 0){
			return 0;
		}
	}
	return 1;
}