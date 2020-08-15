#include<stdio.h>
int main() {

	int id;
	double gpa;
	printf("Enter your student ID : ");
	scanf_s("%d", &id);
	printf("\nEnter your gpa : ");
	scanf_s("%lf", &gpa);
	printf("Welcome!!! %d \n Your grade is %.2lf", id, gpa);



}