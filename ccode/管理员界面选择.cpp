#include<stdio.h>
#include<windows.h>
void choose4(){
	extern void user2();
	extern void delay();
	extern void water();
	extern void waternum();
	extern void change2();
	extern void diedie();
	extern void read();
	extern void watch();
	int a;
	while (1){
		user2();
		printf("����������ѡ��");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:water(); break;
		case 2:waternum(); break;
		case 3:change2(); break;
		case 4:watch(); break;
		case 5:diedie(); break;
		case 6:read(); break;
		case 7:printf("ллʹ��\n");
			delay();
			system("cls");
			exit(0);
		default:
			delay();
			system("cls");
			break;
		}
	}
}