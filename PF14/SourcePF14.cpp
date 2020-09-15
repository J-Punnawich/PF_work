#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n1, n2, i, f;


    scanf("%d %d", &n1, &n2);

    for (i = 1; i <= n1 && i <= n2; ++i)
    {
        
        if (n1 % i == 0 && n2 % i == 0)
            f = i;
    }

    printf("%d", f);

    return 0;
}