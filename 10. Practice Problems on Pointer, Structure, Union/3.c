#include <stdio.h>
#include <stdlib.h>

int myStrlen(char *x) {
    int l = 0;
    while(*x++) {
        l++;
    }
    return l;
}

int check(char *str1, char *str2, int index) {
    while(*str2) {

        if(*(str1+index) != *str2) return 0;
        index++;
        str2++;
    }

    return 1;
}

char *mystrstr( char *str1, char *str2) {

    int l1 = myStrlen(str1);
    int l2 = myStrlen(str2);

    for(int i=0; i <= l1-l2; i++) {
        if(check(str1, str2, i)) {
            return str1+i;
        }
    }

    return NULL;
}

int main()
{
    char *str1 = (char*)malloc(100*sizeof(char));
    char *str2 = (char*)malloc(100*sizeof(char));

    gets(str1);
    gets(str2);

    printf("%s", mystrstr(str1, str2));


    return 0;
}
