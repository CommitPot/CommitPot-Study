#include <stdio.h>

int main() {
    int n;
    long long r = 0;
    char s[200001];
    scanf("%d %s", &n, s);
    for (int i = 0, j = 0; i <= n; i++) {
        if (!s[i] || s[i] == 48) {
            r += (long long) (1 + j) * (j / 2) + (j & 1 ? (j + 1) / 2 : 0);
            j = 0;
        } else j++;
    }
    printf("%lld", r);
}
