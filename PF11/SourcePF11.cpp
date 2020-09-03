#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int test(int x, int i);

int main() {

	int x, i = 1;
	scanf("%d", &x);

	while (i < x) {
		test(x, i);
		i++;

	}

}


int test(int x, int i) {
	if (i >= 0) {

		if (x % i == 0) {
			printf("%d ", i);

		}
	}
	else {
		printf("Error");
	}
	return 0;
}

