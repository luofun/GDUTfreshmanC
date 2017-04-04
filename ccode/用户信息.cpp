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
extern int Aa;
void mess(){
	extern void charge();
	extern void delay();
	user who;
	int i;
	FILE *f;
	f = fopen("user.bin", "rb");
	fseek(f, Aa*sizeof(user), 0);
	fread(&who, sizeof(user), 1, f);
	fclose(f);
	printf("个人信息\n名称：%s\n已消费：%f\n余额：%f\n消费次数：%d\n最后操作时间：%d%,%d,%d\n", who.name, who.rmbmessage.cost, who.rmbmessage.left, who.N, who.rmbmessage.t.year, who.rmbmessage.t.month, who.rmbmessage.t.day);
	printf("是否充值？ 1：是  2：返回\n");
	scanf("%d",&i);
	switch (i)
	{
	case 1:charge(); break;
	default:
		break;
	}
	delay();
	system("cls");
}