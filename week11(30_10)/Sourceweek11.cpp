#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
    char pass[100];
    int len;
    long condition = 0, upperCase{}, downCase{}, n{}, s{};
    scanf("%s",&pass);
    len = strlen(pass);
    if (len >= 3 && len <= 20)
    {
        for (int i = 0; i < len;i++)
        {
            if (pass[i] >= 'A' && pass[i] <= 'Z')
            {

                upperCase += 1;
            }
            
            if ((pass[i] >= 'A' && pass[i] <= 'Z') || (pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= '0' && pass[i] <= '9') || pass[i] == '\0' || pass[i] == '\n')
            {
            }
            if (pass[i] >= '0' && pass[i] <= '9')
            {
                n += 1;
            }
            if (pass[i] >= 'a' && pass[i] <= 'z')
            {
                downCase += 1;
            }
            else
            {
                s += 1;
            }
        }
    }
    else
    {
        printf("Invalid");
        return 0;
    }
    if (upperCase >= 1 && downCase >= 1 && n >= 1  && s >= 1)
    {
        printf("Valid");
    }
    else
    {
        printf("Invalid");
    }


    return 0;
}