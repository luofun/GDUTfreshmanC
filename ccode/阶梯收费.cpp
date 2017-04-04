#include<stdio.h>
float money(float a){
	float end = 0;
	float b;
	FILE *fp;
	fp = fopen("price.dat", "rt");
	fscanf(fp, "%f", &b);
	fclose(fp);
	if (a > 250) end = (a - 250)*1.5*b + 120*b + 150*b;
	else if (a > 150) end = (a - 150) * 1.2*b + 150*b;
	else if (a >= 0) end = a*b;
	return end;
}