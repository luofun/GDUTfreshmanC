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
void charge(){
	extern void delay();
	extern void usermb();
	extern timer gettime();
	float rmb;
	int q=0;
	user who, here;
	FILE *f;
	f = fopen("user.bin", "rb");
	fseek(f, Aa*sizeof(user), 0);
	fread(&who, sizeof(user), 1, f);
	fclose(f);
	do{
		printf("�����ֵ��");
		scanf("%f", &rmb);
		putchar('\n');
		printf("����ȷ�ϣ�");
		scanf("%d", &here.key);
		while (here.key != who.key){
			printf("�������\n�����������룺");
			scanf("%d", &here.key);
			putchar('\n');
		}
		who.rmbmessage.left += rmb;
	} while (who.rmbmessage.left <= 0);
	who.rmbmessage.t = gettime();
	f = fopen("user.bin", "rb+");
	fseek(f, Aa*sizeof(user), 0);
	fwrite(&who, sizeof(user), 1, f);
	fclose(f);
	printf("��ֵ�ɹ������Ϊ��%f",who.rmbmessage.left);
	delay();
	delay();
	system("cls");
}