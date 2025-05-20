#include <stdio.h>

int main() {
    int n, a[500001];
    char s[4000001];
    long long r = 0;
    scanf("%d %[^\n]", &n, s);
    for (int i = 0, v = 0, j = 0; s[i]; i++) {
        if (s[i] == 32) {
            a[j++] = v;
            v = 0;
        } else v = v * 10 + s[i] - 48;
        if (!s[i + 1]) a[j++] = v;
    }
    for (int i = n - 1, j = a[n - 1]; i >= 0; i--) {
        if (a[i] <= j) j = a[i];
        r += j;
    }
    printf("%lld", r);
}
