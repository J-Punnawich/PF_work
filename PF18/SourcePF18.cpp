#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main() {

	double a, b, xbar = 0, temp = 0, pow_xbar = 0;
	scanf("%lf %lf", &a, &b);
	if (a >= 0 && b >= 0)
	{
		if (a < b)
		{
			for (a, b, temp, xbar;a <= b;a++)
			{
				printf("%.0lf ", a);
				xbar += a;
				pow_xbar += pow(a, 2);   // keep sigma x^2 
				temp++;                  // all nums between a and b
			}
			printf("\nAverage = %.1lf", (double)xbar / temp);
			printf("\nSD = %.2f", sqrt((temp * (pow_xbar)-pow(xbar, 2)) / (temp * (temp - 1))));    // calculate S.D.

		}
		else if (b < a)
		{
			for (a, b, temp, xbar;b <= a;a--)
			{
				printf("%.0lf ", a);
				xbar += a;
				pow_xbar += pow(a, 2);
				temp++;
			}
			printf("\nAverage = %.1lf", (double)xbar / temp);
			printf("\nSD = %.2f", sqrt((temp * (pow_xbar)-pow(xbar, 2)) / (temp * (temp - 1))));
		}
	}
	else printf("Error");
}