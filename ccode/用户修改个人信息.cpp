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
	printf("�޸ĺ���û�����");
	scanf("%s",who.name);
	putchar('\n');
	printf("�޸ĺ�����룺");
	scanf("%d",&n);
	printf("\n�ٴ����룺");
	scanf("%d",&who.key);
	putchar('\n');
	if (who.key != n){
		printf("�������벻ͬ��\n");
		printf("�޸ĺ�����룺");
		scanf("%d", &n);
		printf("\n�ٴ����룺");
		scanf("%d", &who.key);
	}
	printf("�޸ĺ�����ƽ�");
	scanf("%f",&who.rmbmessage.limit);
	putchar('\n');
	f = fopen("user.bin", "rb+");
	fseek(f, Aa*sizeof(user), 0);
	fwrite(&who, sizeof(user), 1, f);
	fclose(f);
	printf("�޸ĳɹ�^_^��������%sΪ���˺�\n",who.name);
	delay();
	system("cls");
}