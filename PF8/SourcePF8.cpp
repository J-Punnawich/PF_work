#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
int checkLine(int n) {

    int i = 1, j = 0;
    if (n >= i && n >= 0) {

        for (i = 1; i <= n;) {
            if (i % 2 == 0) {

                for (j = 0;j < n;) {
                    if (j % 2 == 0)
                        printf("_");
                    else
                        printf("*");

                    j = j + 1;
                }
            }

            else
                for (j = 0;j < n;) {
                    if (j % 2 == 0)
                        printf("*");
                    else
                        printf("_");
                    j = j + 1;
                }



            printf("\n");
            i = i + 1;
        }
    } return 0;
} 



int main() {
    int n;
    scanf("%d", &n);
    checkLine(n);



}

