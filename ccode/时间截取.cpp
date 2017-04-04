#include<stdio.h>
#include<time.h>
typedef struct{
	int year;
	int month;
	int day;
}timer;
typedef struct{
	float cost;
	float left;
	float limit;
	timer t;
}card;
typedef struct{
	int num;
	int key;
	int N;
	float count;
	char name[20];
	card rmbmessage;
}user;
typedef struct{
	int num;
	int key;
	char name[20];
}controler;
timer gettime(void){
	timer t;
	time_t nowtime;
	struct tm *timeinfo; 
	time(&nowtime); 
	timeinfo = localtime(&nowtime); 
	t.year = timeinfo->tm_year + 1900;
	t.month = timeinfo->tm_mon + 1;
	t.day = timeinfo->tm_mday;
	return t;
}