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
void change(){
	extern void delay();
	int n;
	user who;
	FILE *f;
	f = fopen("user.bin", "rb");
	fseek(f, Aa*sizeof(user), 0);
	fread(&who, sizeof(user), 1, f);
	fclose(f);
	printf("修改后的用户名：");
	scanf("%s",who.name);
	putchar('\n');
	printf("修改后的密码：");
	scanf("%d",&n);
	printf("\n再次输入：");
	scanf("%d",&who.key);
	putchar('\n');
	if (who.key != n){
		printf("两次输入不同！\n");
		printf("修改后的密码：");
		scanf("%d", &n);
		printf("\n再次输入：");
		scanf("%d", &who.key);
	}
	printf("修改后的限制金额：");
	scanf("%f",&who.rmbmessage.limit);
	putchar('\n');
	f = fopen("user.bin", "rb+");
	fseek(f, Aa*sizeof(user), 0);
	fwrite(&who, sizeof(user), 1, f);
	fclose(f);
	printf("修改成功^_^新姓名：%s为的账号\n",who.name);
	delay();
	system("cls");
}