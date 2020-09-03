#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int kittung(int x);

int main() {
	int x;
	scanf("%d", &x);
	if (x >= 0) {
		kittung(x);

	}
	else printf("Error");


}
int kittung(int x) {
	if (x % 4 == 0) {
		printf("%d Baht", 249 * (x - (x / 4)));
	}
	else {
		x == x;
		printf("%d Baht", 249 * x);
	}
	return 0;
}