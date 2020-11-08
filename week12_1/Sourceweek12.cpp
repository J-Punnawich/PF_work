#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calcu(void) {

	int num[6];

	for (int i = 0; i < 7; i++) {
		scanf_s("%d", &num[i]);

		if (num[i] < -400  ||  num[i] > 400  ) {
			printf("error"); 
			return 0;
		}

		else {

		if (num[i] >= 0 && num[i] <= 400) 
		{
			printf("number Positive integers : %d\n", num[i]);

			if (num[i] % 2 == 0) 
			{
				printf("Even number : %d\n", num[i]);

			}
				else {
					printf("Odd number : %d\n", num[i]);
				}
			}

			if (num[i] < 0 && num[i] >= -400) {
				printf("number Negative integers : %d\n", num[i]);

				if (num[i] % 2 == 0) {
					printf("Even number : %d\n", num[i]);

				}
				else {
					printf("Odd number : %d\n", num[i]);
				}


			}

		}
	}
}

int main() {

	calcu();

	
}

