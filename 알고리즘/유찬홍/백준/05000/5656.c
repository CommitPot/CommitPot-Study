#include <stdio.h>

int main() {
    int n = 1, a, b;
    char s[3];
    while (scanf("%d %s %d", &a, s, &b)) {
        if (*s == 'E') break;
        int r = 0;
        if (*s == '<') r = s[1] != '=' ? a < b : a <= b;
        if (*s == '>') r = s[1] != '=' ? a > b : a >= b;
        if (*s == '=') r = a == b;
        if (*s == '!') r = a != b;
        printf("Case %d: %s\n", n++, r ? "true" : "false");
    }
}
