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
void waternum(){
	extern void delay();
	int u;
	user who;
	FILE *f;
	printf("����Ҫ��¼���û�ע��ţ�");
	scanf("%d",&u);
	putchar('\n');
	f = fopen("user.bin", "rb");
	fseek(f, u*sizeof(user), 0);
	fread(&who, sizeof(user), 1, f);
	fclose(f);
	printf("��¼����Ϊ��");
	scanf("%f",&who.count);
	putchar('\n');
	f = fopen("user.bin", "rb+");
	fseek(f, u*sizeof(user), 0);
	fwrite(&who, sizeof(user), 1, f);
	fclose(f);
	printf("��¼�ɹ�\n");
	delay();
	system("cls");
}