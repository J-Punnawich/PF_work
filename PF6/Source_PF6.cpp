#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a != b) {
		if (a > b) {
			printf("%d <-- These one is better", a);
		}
		else if (b > a) { printf("%d <-- These one is better", b); }
	}
	else printf("%d = %d naja ", a, b);

}

