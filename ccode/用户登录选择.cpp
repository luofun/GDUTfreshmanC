#include<stdio.h>
#include<windows.h>
void on1(){
	extern void login1();
	extern void load1();
	extern void choose3();
	extern void loading();
	extern void delay();
	int a;
	delay();
	system("cls");
	while (1){
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("+++++++++++++++++++             �����û�����              ++++++++++++++++++++++");
		loading();
		printf("����������ѡ��");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:load1(); choose3(); break;
		case 2:login1(); break;
		case 3:printf("ллʹ��\n");
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