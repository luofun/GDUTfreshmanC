#include<stdio.h>
#include<windows.h>
void on2(){
	extern void loading();
	extern void delay();
	extern void login2();
	extern void load2();
	extern void choose4();
	int a;
	delay();
	system("cls");
	while (1){
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("+++++++++++++++++++             ���ǹ���Ա����            ++++++++++++++++++++++");
		loading();
		printf("����������ѡ��");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:load2();choose4(); break;
		case 2:login2();
			break;
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