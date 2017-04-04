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
void give(){
	extern timer gettime(void);
	user who,other;
	FILE *f;
	int b,d;
	float c;
	f = fopen("user.bin", "rb");
	fseek(f, Aa*sizeof(user), 0);
	fread(&who, sizeof(user), 1, f);
	fclose(f);
	printf("输入转账对象的注册号：");
	scanf("%d",&b);
	putchar('\n');
	f = fopen("user.bin", "rb");
	fseek(f, b*sizeof(user), 0);
	fread(&other, sizeof(user), 1, f);
	fclose(f);
	printf("输入转账金额：");
	scanf("%f",&c);
	putchar('\n');
	printf("输入密码：");
	scanf("%d",&d);
	putchar('\n');
	while(who.key != d){
		printf("密码错误，重新输入：");
		scanf("%d", &d);
		putchar('\n');
	}
	who.N++;
	who.rmbmessage.t = gettime();
	other.N++;
	other.rmbmessage.t = gettime();
	who.rmbmessage.left -= c;
	other.rmbmessage.left += c;
	who.rmbmessage.cost += c;
	f = fopen("user.bin", "rb+");
	fseek(f, Aa*sizeof(user), 0);
	fwrite(&who, sizeof(user), 1, f);
	fclose(f);
	f = fopen("user.bin", "rb+");
	fseek(f, b*sizeof(user), 0);
	fwrite(&other, sizeof(user), 1, f);
	fclose(f);
	printf("转账成功\n");
}