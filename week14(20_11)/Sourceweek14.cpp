#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string.h> 

int hextodec(char n[])
{
    int len= strlen(n);
    int base= 1;
    int dec= 0;

    for (int i = len-1; i>=0; i--)
    {
    
        if (n[i] >= '0' && n[i] <= '9')
        {
            dec += (n[i] - 48) * base;

            base = base * 16;
        }

        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            dec += (n[i] - 55) * base;

            base = base * 16;
        }
    }

    return dec;
}


int main()
{   
    char hexNum[5];
    scanf("%s", hexNum);
    std::cout << hextodec(hexNum) << "\n";   
}