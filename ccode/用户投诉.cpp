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
	printf("д����������һ���ֽ����ڣ���");
	scanf("%s",words);
	f = fopen("tou.dat","at");
	fprintf(f,"�û���%d\n�����%s\nʱ�䣺%d,%d,%d\n",Aa,words,tt.year,tt.month,tt.day);
	fclose(f);
	exit(0);
}