#include <stdio.h>

int main() {
    int l = -1;
    long long r = 0, j = 1;
    char s[11];
    scanf("%s", s);
    while (s[++l]);
    l--;
    for (int i = l; i >= 0; i--, j *= 26) r += (s[i] - 64) * j;
    printf("%lld", r);
}
