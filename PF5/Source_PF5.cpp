#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 

int main() {
	int age;
	printf("Enter your age: ");
	scanf("%d", &age);
	if (age > 0) {
		if (age > 0 && age <= 11)
			printf("Kid");
		else if (age > 11 && age <= 20)
			printf("Teen");
		else if (age > 20 && age <= 60)
			printf("Adult");
		else
			printf("Old");
	} else 
		printf("Try again");

	return 0;
}