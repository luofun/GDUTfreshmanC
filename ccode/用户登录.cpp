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
int Aa;
void load1(){
	extern void delay();
	user who,here;
	FILE *f;
	printf("请输入用户注册号：");
	scanf("%d",&Aa);
	putchar('\n');
	f=fopen("user.bin","rb");
	fseek(f,Aa*sizeof(user),0);
	fread(&who,sizeof(user),1,f);
	fclose(f);
	printf("请输入用户名称：");
	scanf("%s",here.name);
	while (strcmp(who.name, here.name) != 0){
		printf("用户名称错误\n重新输入名称：");
		scanf("%s",here.name);
		putchar('\n');
	}
	printf("请输入密码：");
	scanf("%d",&here.key);
	while (here.key!=who.key){
		printf("用户密码错误\n重新输入密码：");
		scanf("%d", &here.key);
		putchar('\n');
	}
	delay();
	system("cls");
	printf("登录成功^_^\n个人信息\n名称：%s\n已消费：%f\n余额：%f\n消费次数：%d\n最后金钱操作时间：%d%,%d,%d\n",who.name,who.rmbmessage.cost,who.rmbmessage.left,who.N,who.rmbmessage.t.year,who.rmbmessage.t.month,who.rmbmessage.t.day);
}