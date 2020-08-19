#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int i, j, n;
	scanf("%d", &n);
	for (i = 1;i <= n;i++) {
		for (j = 1; j <= n; j++) {
			printf("*");
		}
		printf("\n");
	}
}
