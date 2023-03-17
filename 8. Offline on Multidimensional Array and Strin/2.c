#include <stdio.h>
#include <string.h>

int find(char s1[], char s2[], int i, int l2) {

    for(int x = 0; x < l2; x++, i++) {
        if(s2[x] != s1[i]) return 0;
    }

    return 1;
}

void replace(char s1[], char s3[], int i, int check) {

    int l3 = strlen(s3), l1 = strlen(s1);

    if(check == 0) {
        for(int x = 0; x < l3; x++, i++)
            s1[i] = s3[x];
    } else if(check > 0) {
        for(int x = 0; x < l3; x++, i++) // as the l3 is less than l2. So, we can overwrite here
            s1[i] = s3[x];

        while(s1[i] != '\0') {
            s1[i] = s1[check+i];
            i++;
        }

    } else {
        check = -check;
        int z = l1 + check ;

        while(z >= i+l3) {  // Making space for the replaced string as l3 > l2
            s1[z] = s1[z-check];
            z--;
        }

        for(int x = 0; x < l3; x++, i++)
            s1[i] = s3[x];

    }

}

int main()
{
    char s1[503] = {0}, s2[102] = {0}, s3[12] = {0};

    gets(s1);
    gets(s2);
    gets(s3);

    int l1 = strlen(s1), l2 = strlen(s2), l3 = strlen(s3);

    int i = 0, check = l2 - l3;

    while(s1[i] != '\0' && i <= (l1 - l2)) {

        if(find(s1, s2, i, l2)) {
            replace(s1, s3, i, check);

            l1 = strlen(s1);
            i += l3;

        } else {
            i++;
        }
    }

    puts(s1);

    return 0;
}
