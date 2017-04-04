#include<stdio.h>
#include<stdlib.h>
void diedie(){
	extern void delay();
	FILE *f;
	int i,a=0;
	printf("确认初始化？1：确定  2：返回");
	scanf("%d", &i);
	putchar('\n');
	if (i = 1){
		f = fopen("user.bin", "wb");
		fclose(f);
		f = fopen("num.dat", "wt");
		fprintf(f, "%d", a);
		fclose(f);
		f = fopen("tou.dat","wt");
		fclose(f);
		printf("初始化成功\n");
	}
	delay();
	system("cls");
}