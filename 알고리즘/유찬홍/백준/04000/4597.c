#include <stdio.h>

int main() {
    char s[33];
    while (scanf("%s", s), *s != '#') {
        int r = 0, p;
        for (int i = 0; s[i]; i++) {
            r += s[i] == 49;
            if (!s[i + 1]) p = s[i] == 'e', s[i] = 0;
        }
        printf("%s%d\n", s, p ? r & 1 ? 1 : 0 : r & 1 ? 0 : 1);
    }
}
