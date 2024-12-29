#include <stdio.h>

void temp(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int main() {
    char s[11];
    scanf("%[^\n]", s);
    while (1) {
        for (int i = 0; i < 8; i += 2) {
            if (s[i] > s[i + 2]) {
                temp(&s[i], &s[i + 2]);
                printf("%s\n", s);
            }
        }
        if (s[0] < s[2] && s[2] < s[4] && s[4] < s[6] && s[6] < s[8]) break;
    }
}
