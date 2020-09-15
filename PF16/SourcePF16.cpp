#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int top(int);
int base(int);
int main() {
    int n;
    scanf("%d", &n);
    top(n);
    base(n);
   
}
int top(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf("    ");
        }
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                printf("*   ");
            else
            {
                printf("    ");
            }

        }
        printf("\n");
    }
    return 0;
}
int base(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("    ");
        }
        for (int j = n; j > i; j--)
        {
            if (j == i + 1 || j == n)
                printf("*   ");
            else
            {
                printf("    ");
            }
        }
        printf("\n");
    }
    return 0;
}