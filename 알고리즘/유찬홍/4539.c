#include <stdio.h>

int f(char *s) {
    if (!*(s + 1)) return *s;
    return *s += f(s + 1) > 52;
}

int main() {
    int n;
    char s[9];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        printf("%d", f(s) - 48);
        for (int i = 0; s[i]; i++) s[i - 1] = 48, s[i] = 0;
        printf("%s\n", s);
    }
}
