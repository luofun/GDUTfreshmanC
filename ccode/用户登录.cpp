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
	printf("�������û�ע��ţ�");
	scanf("%d",&Aa);
	putchar('\n');
	f=fopen("user.bin","rb");
	fseek(f,Aa*sizeof(user),0);
	fread(&who,sizeof(user),1,f);
	fclose(f);
	printf("�������û����ƣ�");
	scanf("%s",here.name);
	while (strcmp(who.name, here.name) != 0){
		printf("�û����ƴ���\n�����������ƣ�");
		scanf("%s",here.name);
		putchar('\n');
	}
	printf("���������룺");
	scanf("%d",&here.key);
	while (here.key!=who.key){
		printf("�û��������\n�����������룺");
		scanf("%d", &here.key);
		putchar('\n');
	}
	delay();
	system("cls");
	printf("��¼�ɹ�^_^\n������Ϣ\n���ƣ�%s\n�����ѣ�%f\n��%f\n���Ѵ�����%d\n����Ǯ����ʱ�䣺%d%,%d,%d\n",who.name,who.rmbmessage.cost,who.rmbmessage.left,who.N,who.rmbmessage.t.year,who.rmbmessage.t.month,who.rmbmessage.t.day);
}