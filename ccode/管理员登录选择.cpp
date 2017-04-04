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
		printf("+++++++++++++++++++             这是管理员界面            ++++++++++++++++++++++");
		loading();
		printf("请输入您的选择：");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:load2();choose4(); break;
		case 2:login2();
			break;
		case 3:printf("谢谢使用\n");
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