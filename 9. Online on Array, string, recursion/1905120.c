#include <stdio.h>
#include <string.h>

int countSubsequence(char s1[], char s2[], int l1, int l2) {
    if(l2 == 0) return 1;

    if(l1 == 0) return 0;

    if(s1[l1-1] == s2[l2-1]) {
        return countSubsequence(s1, s2, l1-1, l2-1) + countSubsequence(s1, s2, l1-1, l2);
    } else {
        return countSubsequence(s1, s2, l1-1, l2);
    }


}

int main()
{

    char s1[30] = "";
    char s2[30] = "";

    gets(s1);
    gets(s2);

    printf("%d", countSubsequence(s1, s2, strlen(s1), strlen(s2)));

    return 0;
}
