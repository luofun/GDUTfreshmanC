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
	printf("���������Աע��ţ�");
	scanf("%d", &Bb);
	putchar('\n');
	f = fopen("controler.bin", "rb");
	fseek(f, Bb*sizeof(controler), 0);
	fread(&who, sizeof(controler), 1, f);
	fclose(f);
	printf("���������Ա���ƣ�");
	scanf("%s", here.name);
	putchar('\n');
	while (strcmp(who.name, here.name) != 0){
		printf("����Ա���ƴ���\n�����������ƣ�");
		scanf("%s", here.name);
		putchar('\n');
	}
	printf("���������룺");
	scanf("%d", &here.key);
	while (here.key != who.key){
		i++;
		printf("�û��������\n�����������룺");
		scanf("%d", &here.key);
		putchar('\n');
		if (i == 3){
			printf("�������������\n");
			delay();
			exit(0);
		}
	}
	delay();
	system("cls");
	printf("��¼�ɹ�������Ա��%s\n",who.name);
}