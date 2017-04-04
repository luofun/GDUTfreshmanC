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
void usermb(){
	extern float money(float a);
	extern void delay();
	extern timer gettime();
	float rmb;
	int u=0,i=0;
	user who;
	FILE *f;
	f = fopen("user.bin", "rb");
	fseek(f, Aa*sizeof(user), 0);
	fread(&who, sizeof(user), 1, f);
	fclose(f);
	printf("已用水电气度数为%f\n开始自动缴费\n",who.count);
	rmb = money(who.count);
	if (rmb >= who.rmbmessage.limit){
		do{	
			printf("超过每次限额，请输入密码：");
			scanf("%d", &u);
			putchar('\n');
		} while (u != who.key);
	}
	who.rmbmessage.cost += rmb;
	who.rmbmessage.left -= rmb;
	who.N++;
	who.count = 0;
	who.rmbmessage.t = gettime();
	f = fopen("user.bin", "rb+");
	fseek(f, Aa*sizeof(user), 0);
	fwrite(&who, sizeof(user), 1, f);
	fclose(f);
	f = fopen("user.bin", "rb+");
	fseek(f, Aa*sizeof(user), 0);
	fwrite(&who, sizeof(user), 1, f);
	fclose(f);
	printf("缴费成功，余额为：%f\n已消费：%f\n消费次数：%d\n", who.rmbmessage.left,who.rmbmessage.cost,who.N);
	if(who.rmbmessage.left <= 0){
		printf("余额不足即将停止服务，请充值\n");
	}
	printf("返回？1：是  ");
	scanf("%d",&i);
	putchar('\n');
	while (i != 1){
		scanf("%d", &i);
		putchar('\n');
	}
	delay();
	system("cls");
}