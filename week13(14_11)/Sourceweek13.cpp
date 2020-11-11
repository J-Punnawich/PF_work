#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void triangle(int* pt_a)
{
	int i, star;

	for (i = *pt_a;i <= *pt_a && i > 0;i--)
	{
		for (star = i;star <= i && star > 0; star--)
		{
			printf("* ");
		}
		printf("\n");
	}
}


int main()
{
	int a;
	scanf("%d", &a);
	int* pt_a = &a;
	triangle(pt_a);

}