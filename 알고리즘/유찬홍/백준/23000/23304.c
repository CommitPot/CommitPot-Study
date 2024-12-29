#include <stdio.h>
#include <string.h>

int f(char *s, int a, int b) {
    if (b - a < 3) return ~(b - a) & 1 && s[a] == s[b];
    int m = (a + b) / 2;
    return f(s, a, m - (~(b - a) & 1)) && f(s, m + 1, b);
}

int main() {
    char s[2000001];
    scanf("%s", s);
    printf("%s", f(s, 0, strlen(s) - 1) ? "AKARAKA" : "IPSELENTI");
}
