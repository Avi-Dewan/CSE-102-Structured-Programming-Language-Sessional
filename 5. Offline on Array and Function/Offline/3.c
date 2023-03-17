#include <stdio.h>
#include <string.h>

int main()
{
    int a[102] = {0};

    int n, max = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] > max) max = a[i];
    }

    if( n == 1) {   // As n was an edge case in my algorithm
        for(int i = 0; i < a[0]; i++)
            printf("**\n");
    } else {

        for(int i = 0; i < n; i++) {
            a[i] = max - a[i]; // as an example if it is 2, then we start printing ** from 5th line. (6-2) = (max - a[i] = 4
        }


        for(int i = 1; i <= max; i++) {
            for(int j = 0; j < n; j++) {

                if(j != n-1) {
                   if(i > a[j]) printf("** "); // as an example(taken from prev one), here a[j]= 4. Then, it will start from 5th line
                   else printf("   ");
                } else { // as we don't want to print extra space we're separating it as another case
                    if(a[j] < i) printf("**");
                   else printf("  ");
                }

            }

            printf("\n");

        }

    }




}
