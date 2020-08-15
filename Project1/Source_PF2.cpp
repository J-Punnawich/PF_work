#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char main() {

	char name[20];
	int pass;
	printf("Enter your username : ");
	scanf("%s", &name);
	printf("Hi! %s \nAnd your password ? : ", name);

	scanf("%d", &pass);
	printf("Welcome!!! %s \n nice to see you again!", name);



}