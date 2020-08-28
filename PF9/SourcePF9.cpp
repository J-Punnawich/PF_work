#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int dorkJun() {
	printf("*");
	return 0;
}
int box(int n) {
	int i, j;
	for (i = 0;i <= n;i++) {
		printf("*");
		for (j = 0;j <= n;j++) {

			if (i == 0 || i == n || j == n) {
				dorkJun();
			}
			else printf(" ");

		}
		printf("\n");
	}
	return n;
}
int main()
{
	int n;
	scanf("%d", &n);
	box(n);
	
}
