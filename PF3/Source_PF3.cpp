#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 

int main() {
	double a[5];
	printf("Enter 3 values : ");
	scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);

	printf("Average = %.2lf", (a[0] + a[1] + a[2]) / 3);
}