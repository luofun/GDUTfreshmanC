#include<stdio.h>
void delay(){
	int i, j, k;
	for (i = 1; i < 1000; i++)
		for (j = 1; j < 1000; j++)
			for (k = 1; k < 1000; k++);
}