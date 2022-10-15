#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
void main()
{
	float dof, doc, dok;
	printf("Do C = ");
	scanf("%f",&doc);
	dof = doc * 1.8 + 32;
	dok = doc + 273;
	printf("Do F= %.1f\n",dof);
	printf("Do K= %.1f\n",dok);
}
