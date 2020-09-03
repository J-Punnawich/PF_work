#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int isPrime(int x) {
	int c = 0, i = 1;

	if (x >= 0) {

		while (i <= x)         // run from 1 to ....
		{
			if (x % i == 0) {     // if x%1 == 0   c++; }             
				c++;               // count++ 

			}
			i++;                // increase i
		}
		if (c == 2) {       // if there's only 2 number that made modulo x == 0


			return 1;       // return 1 --> Prime Number
		}                            

		else {
			return 0;
		}

	}
	else {
		return 0;
	}

}

int main() {
	int x;
	scanf("%d", &x);

	if (isPrime(x) == 1) {
		printf("Prime Number");
	}

	else if (isPrime(x) == 0) {
		printf("Not Prime Number");
	}

}

