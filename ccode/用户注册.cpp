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
void login1(){
	extern void delay();
	extern timer gettime();
	user one;
	FILE *fp,*fp1,*fp2;
	int a,b=0;
	one.key = 123456;
	fp=fopen("num.dat","rt");
	fscanf(fp, "%d", &a); 
	one.num = a;
	a++;
	fclose(fp);
	printf("���ע��ţ�%d\n", one.num);
	if ((fp2 = fopen("user.bin", "ab")) == NULL){
		printf("�򲻿��û��ļ�\n");
		exit(0);
	}
	printf("�������û����ƣ�");
	scanf("%s",one.name);
	putchar('\n');
	while (b != one.key){
		printf("���������룺");
		scanf("%d", &b);
		printf("�ٴ��������룺");
		scanf("%d", &one.key);
		putchar('\n');
		if (b != one.key)
			printf("������������");
		putchar('\n');
	}
	printf("���뵥�ν�����ޣ�");
	scanf("%f",&one.rmbmessage.limit);
	putchar('\n');
	printf("�״γ�ֵ��");
	scanf("%f",&one.rmbmessage.left);
	putchar('\n');
	one.rmbmessage.cost = 0;
	one.N = 0;
	one.count = 0;
	one.rmbmessage.t = gettime();
	printf("��ǰʱ�䣺%d,%d,%d\n",one.rmbmessage.t.year,one.rmbmessage.t.month,one.rmbmessage.t.day);
	fflush(stdin);
	if ((fwrite(&one, sizeof(user), 1, fp2)) != 1){
		printf("д�����\n"); 
		exit(0);
	}
	fclose(fp2);
	fp1 = fopen("num.dat", "wt");
	fprintf(fp1, "%d", a);
	fclose(fp1);
	printf("д�����\n");
	delay();
	system("cls");
}