#include<stdio.h>
#include<windows.h>
void choose3(){
	extern void charge();
	extern void usermb();
	extern void change();
	extern void die1();
	extern void tou();
	extern void mess();
	extern void user1();
	extern void delay();
	extern void give();
	int a;
	while (1){
		user1();
		printf("请输入您的选择：");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:charge(); break;
		case 2:usermb(); break;
		case 3:mess(); break;
		case 4:change(); break;
		case 5:give(); break;
		case 6:tou(); break;
		case 7:die1(); break;
		case 8:printf("谢谢使用\n");
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