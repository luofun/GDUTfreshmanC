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
		printf("超过可注册人数！！！\n");
		delay();
		delay();
		system("cls");
		exit(0);
	}
	one.num = a;
	printf("你的注册号：%d\n", one.num);
	if ((fp2 = fopen("controler.bin", "ab")) == NULL){
		printf("打不开管理员文件\n");
		exit(0);
	}
	printf("请输入管理员名称：");
	scanf("%s", one.name);
	putchar('\n');
	while (some!=one.key){
		printf("请输入密码：");
		scanf("%d",&some);
		putchar('\n');
		printf("再次输入密码：");
		scanf("%d",&one.key);
		putchar('\n');
		if (some!=one.key)
			printf("两次密码有误");
		putchar('\n');
	}
	fflush(stdin);
	if ((fwrite(&one, sizeof(controler), 1, fp2)) != 1){
		printf("写入错误\n");
		exit(0);
	}
	fclose(fp2);
	a++;
	fp1 = fopen("cnum.dat", "wt");
	fprintf(fp1, "%d", a);
	fclose(fp1);
	printf("写入完成\n");
	delay();
	system("cls");
}