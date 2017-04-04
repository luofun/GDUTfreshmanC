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
	printf("输入要记录的用户注册号：");
	scanf("%d",&u);
	putchar('\n');
	f = fopen("user.bin", "rb");
	fseek(f, u*sizeof(user), 0);
	fread(&who, sizeof(user), 1, f);
	fclose(f);
	printf("记录度数为：");
	scanf("%f",&who.count);
	putchar('\n');
	f = fopen("user.bin", "rb+");
	fseek(f, u*sizeof(user), 0);
	fwrite(&who, sizeof(user), 1, f);
	fclose(f);
	printf("记录成功\n");
	delay();
	system("cls");
}