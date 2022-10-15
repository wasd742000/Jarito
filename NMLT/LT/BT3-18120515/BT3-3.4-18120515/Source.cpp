#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
void main()
{
	int t1, t2, khoangcach, h1, h2, m1, m2, s1, s2;
	printf("Thoi diem T1 (h m s)= ");
	scanf("%d%d%d",&h1,&m1,&s1);
	printf("Thoi diem T2 (h m s)= ");
	scanf("%d%d%d",&h2,&m2,&s2);
	t1 = h1*3600 + m1*60 + s1;
	t2 = h2*3600 + m2*60 + s2;
    khoangcach = t2 - t1;
	printf("Khoang cach= %d\n", khoangcach);
}