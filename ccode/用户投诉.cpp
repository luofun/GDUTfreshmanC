#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int year;
	int month;
	int day;
}timer;
extern int Aa;
void tou(){
	extern timer gettime();
	timer tt;
	tt = gettime();
	char words[100];
	FILE *f;
	printf("写出你的意见（一百字节以内）：");
	scanf("%s",words);
	f = fopen("tou.dat","at");
	fprintf(f,"用户：%d\n意见：%s\n时间：%d,%d,%d\n",Aa,words,tt.year,tt.month,tt.day);
	fclose(f);
	exit(0);
}