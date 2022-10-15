//Bai 5.3: in bang ma ASCII
#include <stdio.h>
#include <stdlib.h>
void main(){
	printf("Bang ma ASCII: \n");
	system("pause");
	for (int i = 0; i <= 255; i++){
		printf("%d: %c\n", i, i);
	}
}