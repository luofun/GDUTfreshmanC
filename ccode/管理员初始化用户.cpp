#include<stdio.h>
#include<stdlib.h>
void diedie(){
	extern void delay();
	FILE *f;
	int i,a=0;
	printf("ȷ�ϳ�ʼ����1��ȷ��  2������");
	scanf("%d", &i);
	putchar('\n');
	if (i = 1){
		f = fopen("user.bin", "wb");
		fclose(f);
		f = fopen("num.dat", "wt");
		fprintf(f, "%d", a);
		fclose(f);
		f = fopen("tou.dat","wt");
		fclose(f);
		printf("��ʼ���ɹ�\n");
	}
	delay();
	system("cls");
}