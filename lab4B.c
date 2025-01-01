#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool backspaceCompare(char* s, char* t) {
    int i = strlen(s) - 1, j = strlen(t) - 1;

    while (i >= 0 || j >= 0) {
        int skipS = 0, skipT = 0;

        while (i >= 0 && (s[i] == '#' || skipS > 0)) {
            if (s[i] == '#') skipS++;
            else skipS--;
            i--;
        }

        while (j >= 0 && (t[j] == '#' || skipT > 0)) {
            if (t[j] == '#') skipT++;
            else skipT--;
            j--;
        }

        if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
        if ((i >= 0) != (j >= 0)) return false;

        i--;
        j--;
    }

    return true;
}

int main() {
    char s1[] = "ab#c";
    char t1[] = "ad#c";
    printf("Compare '%s' and '%s': %s\n", s1, t1, backspaceCompare(s1, t1) ? "true" : "false");

    char s2[] = "ab##";
    char t2[] = "c#d#";
    printf("Compare '%s' and '%s': %s\n", s2, t2, backspaceCompare(s2, t2) ? "true" : "false");

    char s3[] = "a#c";
    char t3[] = "b";
    printf("Compare '%s' and '%s': %s\n", s3, t3, backspaceCompare(s3, t3) ? "true" : "false");

    return 0;
}
