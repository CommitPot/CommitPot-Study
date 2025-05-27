#include <stdio.h>

int main() {
    char s[1000001];
    scanf("%s", s);
    long long r = *s == 'd' ? 10 : 26, m = 1000000009;
    for (int i = 1; s[i]; i++) {
        r = r * ((s[i] == 'd' ? 10 : 26) - (s[i] == s[i - 1])) % m;
    }
    printf("%lld", r);
}
