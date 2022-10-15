#include "xl2.h"


/* ham tinh tong cac phan tu trong mang 2 chieu ngoai tru phan tu x dang xet:
- m, n lan luot la do dai mang ngang va doc.
- vtn, vtd lan luot la vi tri ngang va doc cua phan tu dang xet.
- sn, sd lan luot la tong ngang va doc.
*/


void sum_x(int a[][100], int m, int n, int vtn, int vtd, int &sn, int &sd){
	sn = 0, sd = 0;
	// Tinh tong hang ngang	
	for (int i = 0; i < m; i++){
		if (i != vtn){
			sn += a[i][vtd];
		}
	}
	// Tinh tong hang doc 
	for (int i = 0; i < n; i++){
		if (i != vtd){
			sd += a[vtn][i];
		}
	}
}


