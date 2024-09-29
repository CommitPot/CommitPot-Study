#include <stdio.h>
#include <string.h>

int f(const char *a, int k) {
    int i, x = 0;
    for (i = 0; a[i]; i++) {
        if (i == k) continue;
        x = x * 10 + a[i] - 48;
    }
    return x;
}

int main() {
    long long s[10] = {}, r = 0;
    char a[11], b[11];
    scanf("%s %s", a, b);
    for (int k = strlen(b) - 1, i = 1; k >= 0; k--, i *= 10) {
        for (int j = 1; j < 10; j++) {
            if (b[k] == j + 48) s[j] += f(b, k) + 1;
            else s[j] += f(b, k) / i * i + (b[k] > j + 48 ? i : 0);
        }
    }
    for (int k = strlen(a) - 1, i = 1; k >= 0; k--, i *= 10) {
        for (int j = 0; j < 10; j++) {
            if (a[k] == j + 48) s[j] -= f(a, k) + 1 - (j ? 0 : i);
            else s[j] -= f(a, k) / i * i + (a[k] > j + 48 && j ? i : 0);
        }
    }
    for (int i = 0; a[i]; i++) s[a[i] - 48]++;
    for (int i = 1; i < 10; i++) r += s[i] * i;
    printf("%lld", r);
}
