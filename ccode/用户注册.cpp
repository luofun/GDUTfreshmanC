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
	printf("你的注册号：%d\n", one.num);
	if ((fp2 = fopen("user.bin", "ab")) == NULL){
		printf("打不开用户文件\n");
		exit(0);
	}
	printf("请输入用户名称：");
	scanf("%s",one.name);
	putchar('\n');
	while (b != one.key){
		printf("请输入密码：");
		scanf("%d", &b);
		printf("再次输入密码：");
		scanf("%d", &one.key);
		putchar('\n');
		if (b != one.key)
			printf("两次密码有误");
		putchar('\n');
	}
	printf("输入单次金额上限：");
	scanf("%f",&one.rmbmessage.limit);
	putchar('\n');
	printf("首次充值金额：");
	scanf("%f",&one.rmbmessage.left);
	putchar('\n');
	one.rmbmessage.cost = 0;
	one.N = 0;
	one.count = 0;
	one.rmbmessage.t = gettime();
	printf("当前时间：%d,%d,%d\n",one.rmbmessage.t.year,one.rmbmessage.t.month,one.rmbmessage.t.day);
	fflush(stdin);
	if ((fwrite(&one, sizeof(user), 1, fp2)) != 1){
		printf("写入错误\n"); 
		exit(0);
	}
	fclose(fp2);
	fp1 = fopen("num.dat", "wt");
	fprintf(fp1, "%d", a);
	fclose(fp1);
	printf("写入完成\n");
	delay();
	system("cls");
}