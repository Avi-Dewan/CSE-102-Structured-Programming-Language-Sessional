#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * prepend(char * s, char * t, int pos) {
    int l1 = strlen(s), l2 = strlen(t);

    int size = l1 - pos + l2 + 1;

    char *new = (char*)malloc(size * sizeof(char));

    char *track = new;

    for(int i = pos; i < l1; i++) {
        *track = s[i];
        track++;
    }

    for(int i = 0; i < l2; i++) {
        *track = t[i];
        track++;
    }

    *track = '\0';


    return new;

}

int main()
{
    char s[100] = "";
    char t[100] = "";
    int pos;

    gets(s);
    gets(t);
    scanf("%d", &pos);

    char *n = prepend(s, t, pos);

    puts(n);

    free(n);

    return 0;
}
