#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n >= 1)
    {
        for (int row = 1; row <= n * 2 - 1; row++)
        {
            for (int i = 1, temp = (row <= n) ? row : (n * 2) - row; i < temp; i++)

                printf(" ");

            printf("*");

            for (int j = 0, temp = (row != n && row < n) ? (n - row) * 2 - 1 : (row - n) * 2 - 1; j < temp; j++)

                printf(" ");

            printf((row == n) ? "\n" : "*\n");
        }
    }
    else
        printf("Error");
    return 0;
}