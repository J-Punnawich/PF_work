#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int az(char str);
int main() {
    // run a to (input) 
    int str;
    scanf("%c", &str);

    az(str);

}
int az(char str)
{

    if (str >= 'A' && str <= 'Z')
    {
        for (int i = 'A'; i <= str; i++)
        {

            printf("%c", i);


        }
    }
    else if (str >= 'a' && str <= 'z')
    {

        for (int i = 'a'; i <= str; i++)
        {

            printf("%c", i);


        }

    }

    return 0;
}


