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
		printf("+++++++++++++++++++             这是用户界面              ++++++++++++++++++++++");
		loading();
		printf("请输入您的选择：");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:load1(); choose3(); break;
		case 2:login1(); break;
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