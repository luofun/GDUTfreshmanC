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
void water(){
	extern void delay();
	FILE *fp,*fp1;
	float b;
	fp = fopen("price.dat", "rt");
	fscanf(fp, "%f", &b);
	fclose(fp);
	printf("���ڵ���Ϊ%f\n",b);
	printf("�����޸ĺ�۸�");
	scanf("%f",&b);
	putchar('\n');
	fp1 = fopen("price.dat", "wt");
	fprintf(fp1, "%f",b);
	fclose(fp1);
	printf("�޸ĳɹ�\n");
	delay();
	system("cls");
}