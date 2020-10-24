#include<stdio.h>
int star(int);
int num;
int* p1;

int main() {
	
	printf("enter number : ");
	scanf_s("%d", &num);
	p1 = &num;
	if (*p1 > 0 && *p1 <= 30) {

		star(*p1);

	}

	else {
		printf("ERROR");
	}

	return 0;
}

int star(int x) {

	for (int i = 1; i <= *p1; i++) {

		for (int j = 1; j <= *p1; j++) {

			if (j == 1 || i == 1 || i == *p1 || j == *p1 || j == (*p1 - i + 1) || i == j) {
				printf("*");
			}
			else {
				printf(" ");
			}

		}
		printf("\n");

	}

	return x;
}