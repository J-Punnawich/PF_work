#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int palin(char str[]);
int main()
{
    char str[200];

    printf("Please enter a word to check Palindrome : ");
    scanf("%s", str);
    printf("\nEntered word: %s", str);
    palin(str);
}
int palin(char str[])
{
    int strLen, i = 0;
    int* pt_strLen = &strLen;

    while (1)
    {
        *pt_strLen = strlen(str) - (i + 1);

        if (str[i] == str[*pt_strLen])
        {
            if (i == *pt_strLen || i + 1 == *pt_strLen)
            {
                printf("\nEntered word \"%s\" is a palindrome", str);
                break;
            }
            i = i + 1;
        }
        else
        {
            printf("\nEntered word \"%s\" is not a palindrome", str);
            break;
        }
    }
    return 0;
}