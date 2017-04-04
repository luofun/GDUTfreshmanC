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
int Bb;
void load2(){
	extern void delay();
	controler who, here;
	FILE *f;
	int i=0;
	printf("请输入管理员注册号：");
	scanf("%d", &Bb);
	putchar('\n');
	f = fopen("controler.bin", "rb");
	fseek(f, Bb*sizeof(controler), 0);
	fread(&who, sizeof(controler), 1, f);
	fclose(f);
	printf("请输入管理员名称：");
	scanf("%s", here.name);
	putchar('\n');
	while (strcmp(who.name, here.name) != 0){
		printf("管理员名称错误\n重新输入名称：");
		scanf("%s", here.name);
		putchar('\n');
	}
	printf("请输入密码：");
	scanf("%d", &here.key);
	while (here.key != who.key){
		i++;
		printf("用户密码错误\n重新输入密码：");
		scanf("%d", &here.key);
		putchar('\n');
		if (i == 3){
			printf("超过可输入次数\n");
			delay();
			exit(0);
		}
	}
	delay();
	system("cls");
	printf("登录成功，管理员：%s\n",who.name);
}