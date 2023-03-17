#include <stdio.h>
#include <string.h>

int checkVowel(char x) {
    if(x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x ==
    'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U')
        return 1;
    return 0;
}

void removeVowel(char a[]) {
    int length =  strlen(a), i = 0;

    while(a[i] != '\0') {
        if(checkVowel(a[i])) {
            int j = i;
            while(a[j] != '\0') {
                a[j] = a[j+1];
                j++;
            }
            a[j] = a[j+1];
        }
        i++;
    }

}

int main()
{
    char a[101] = {0};
    scanf("%101[^\n]", a);

    removeVowel(a);
    puts(a);

}
