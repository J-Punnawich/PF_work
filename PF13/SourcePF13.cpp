#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	double a, b, c, determinant, root1, root2, realPart, imaginaryPart;
	printf("Enter coefficients a, b and c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	determinant = (b * b) - (4 * a * c);  // <- ใส่วงเล็บแยกทำงาน
	// condition for real and different roots (#1)
	if (determinant > 0)
	{
		// sqrt() function returns square root
		root1 = (-b + sqrt(determinant)) / (2 * a);
		root2 = (-b - sqrt(determinant)) / (2 * a);  // <- ใส่วงเล็บแยกการทำงาน
		printf("root1 = %.2lf and root2 = %.2lf", root1, root2); // (#2)
	}

		//condition for real and equal roots
	else if (determinant == 0)
	{
		root1 = root2 = -b / (2 * a); // <- ใส่วงเล็บแยกการทำงาน
		printf("root1 = root2 = %.2lf;", root1); // (#3)
	}
	// if roots are not real
	else
	{
		realPart = -b / (2 * a); //< -ใส่วงเล็บแยกการทำงาน
		imaginaryPart = sqrt(-determinant) / (2 * a); //< -ใส่วงเล็บแยกการทำงาน
		printf("root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi", realPart, imaginaryPart,
			realPart, imaginaryPart); // (#4)
	}

	return 0;
}