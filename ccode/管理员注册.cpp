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
void login2(){
	extern void delay();
	controler one;
	int some = 1234456;
	int a;
	FILE *fp,*fp1, *fp2;
	fp = fopen("cnum.dat", "rt");
	fscanf(fp, "%d", &a);
	fclose(fp);
	if (a >= 3){
		printf("������ע������������\n");
		delay();
		delay();
		system("cls");
		exit(0);
	}
	one.num = a;
	printf("���ע��ţ�%d\n", one.num);
	if ((fp2 = fopen("controler.bin", "ab")) == NULL){
		printf("�򲻿�����Ա�ļ�\n");
		exit(0);
	}
	printf("���������Ա���ƣ�");
	scanf("%s", one.name);
	putchar('\n');
	while (some!=one.key){
		printf("���������룺");
		scanf("%d",&some);
		putchar('\n');
		printf("�ٴ��������룺");
		scanf("%d",&one.key);
		putchar('\n');
		if (some!=one.key)
			printf("������������");
		putchar('\n');
	}
	fflush(stdin);
	if ((fwrite(&one, sizeof(controler), 1, fp2)) != 1){
		printf("д�����\n");
		exit(0);
	}
	fclose(fp2);
	a++;
	fp1 = fopen("cnum.dat", "wt");
	fprintf(fp1, "%d", a);
	fclose(fp1);
	printf("д�����\n");
	delay();
	system("cls");
}