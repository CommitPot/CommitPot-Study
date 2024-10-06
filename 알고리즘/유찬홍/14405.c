#include <stdio.h>

int f(char *s) {
    if (!*s) return 1;
    if (s[0] == 'p' && s[1] == 'i' || s[0] == 'k' && s[1] == 'a') return f(s + 2);
    if (s[0] == 'c' && s[1] == 'h' && s[2] == 'u') return f(s + 3);
    return 0;
}

int main() {
    char s[5001];
    scanf("%s", s);
    printf("%s", f(s) ? "YES" : "NO");
}
