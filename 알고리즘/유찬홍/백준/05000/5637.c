#include <stdio.h>
#include <string.h>

int main() {
    int l = 0;
    char s[10001], r[101];
    while (scanf("%s", s), strcmp(s, "E-N-D")) {
        char c[101];
        int j = 0;
        for (int i = 0; s[i]; i++) {
            if ((64 < s[i] && s[i] < 91) || (96 < s[i] && s[i] < 123) || s[i] == 45) c[j++] = s[i] < 91 && s[i] > 45 ? s[i] + 32 : s[i];
            else {
                if (l < j) {
                    l = j;
                    strcpy(r, c);
                }
                j = 0;
            }
        }
        if (l < j) {
            l = j;
            strcpy(r, c);
        }
    }
    printf("%s", r);
}
