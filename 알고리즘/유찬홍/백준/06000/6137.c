#include <stdio.h>

int main() {
    int n, f = 0, l = 0;
    char s[2001], r[2030];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf(" %c", &s[i]);
    n--;
    while (f <= n) {
        if (s[f] != s[n]) r[l++] = s[f] < s[n] ? s[f++] : s[n--];
        else {
            int F = f, N = n;
            while (s[++F] == s[--N]);
            r[l++] = s[F] < s[N] ? s[f++] : s[n--];
        }
        if (l % 81 == 80) r[l++] = '\n';
    }
    r[l] = 0;
    printf("%s", r);
}
