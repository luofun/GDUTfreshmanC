#include<stdio.h>
#include<windows.h>
void main(){
	extern void on1();
	extern void on2();
	extern void delay();
	void outside();
	int a;
	while (1){
		outside();
		printf("����������ѡ��");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:on2(); break;
		case 2:on1(); break;
		case 3:
			printf("ллʹ��\n");
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