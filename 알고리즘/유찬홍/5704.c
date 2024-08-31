#include <stdio.h>

int main() {
    char s[201];
    while (scanf(" %[^\n]", s), s[0] != '*') {
        int a[26] = {}, r = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == ' ') continue;
            a[s[i] - 97]++;
        }
        for (int i = 0; i < 26; i++) if (!a[i]) r = 1;
        printf("%c\n", r ? 'N' : 'Y');
    }
}
