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
void watch(){
	extern void delay();
	int u,a;
	user who;
	FILE *f;
	printf("����Ҫ�鿴���û�ע��ţ�");
	scanf("%d", &u);
	putchar('\n');
	f = fopen("user.bin", "rb");
	fseek(f, u*sizeof(user), 0);
	fread(&who, sizeof(user), 1, f);
	fclose(f);
	printf("�û�ע��ţ�%d\n������%s\n��%f\n�����ѣ�%f���Ѵ�����%d\n����Ǯ����ʱ�䣺%d,%d,%d\n",who.num,who.name,who.rmbmessage.left,who.rmbmessage.cost,who.N,who.rmbmessage.t.year,who.rmbmessage.t.month,who.rmbmessage.t.day);
	printf("�Ƿ񷵻أ�1������");
	scanf("%d", &a);
	putchar('\n');
	while (a != 1){
		scanf("%d", &a);
		putchar('\n');
	}
	delay();
	system("cls");
}