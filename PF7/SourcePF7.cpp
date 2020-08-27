#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int triangle(int n) {
	int level, row;
	for (row = 0;row < n;row++) {

		for (level = 0;level <= row;level++) {


			printf("*");
		} {

			printf("\n"); }
	}
	return 0;
}


int main() {
	int n;
	scanf("%d", &n);
	if (n >= 0) {
		triangle(n);
	}
	else printf("Error");
}