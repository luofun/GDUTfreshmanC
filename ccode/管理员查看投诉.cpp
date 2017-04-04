#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int year;
	int month;
	int day;
}timer;
typedef struct{
	float cost;
	float left;
	float limit;
	timer t;
}card;
typedef struct{
	int num;
	int key;
	int N;
	float count;
	char name[20];
	card rmbmessage;
}user;
typedef struct{
	int num;
	int key;
	char name[20];
}controler;
void read(){
	extern void delay();
	FILE *f;
	int a;
	f = fopen("tou.dat","rt");
	while (!feof(f)) putchar(getc(f));
	putchar('\n');
	fclose(f);
	printf("ÊÇ·ñ·µ»Ø£¿1£º·µ»Ø");
	scanf("%d",&a);
	putchar('\n');
	while (a != 1){
		scanf("%d", &a);
		putchar('\n');
	}
	delay();
	system("cls");
}