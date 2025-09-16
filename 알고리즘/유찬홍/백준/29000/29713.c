#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int a[26] = {}, r = 1e9;
    char s[1001], *p = "BONZSILV", *q = "RE";
    scanf("%*d %s", s);
    for (int i = 0; s[i]; i++) a[s[i] - 65]++;
    for (int i = 0; p[i]; i++) r = min(r, a[p[i] - 65]);
    for (int i = 0; q[i]; i++) r = min(r, a[q[i] - 65] / 2);
    printf("%d", r);
}
