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
extern int Bb;
void change2(){
	extern void delay();
	controler who;
	FILE *f;
	int n;
	f = fopen("controler.bin", "rb");
	fseek(f, Bb*sizeof(controler), 0);
	fread(&who, sizeof(controler), 1, f);
	fclose(f);
	printf("�����֣�");
	scanf("%s",who.name);
	putchar('\n');
	printf("�����룺");
	scanf("%d", &n);
	printf("\n�ٴ����룺");
	scanf("%d", &who.key);
	putchar('\n');
	if (who.key != n){
		printf("�������벻ͬ��\n");
		printf("�޸ĺ�����룺");
		scanf("%d", &n);
		printf("\n�ٴ����룺");
		scanf("%d", &who.key);
	}
	f = fopen("controler.bin", "rb+");
	fseek(f, Bb*sizeof(controler), 0);
	fwrite(&who, sizeof(controler), 1, f);
	fclose(f);
	printf("�޸ĳɹ�\n");
	delay();
	system("cls");
}