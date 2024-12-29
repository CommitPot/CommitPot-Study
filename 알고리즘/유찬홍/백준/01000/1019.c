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
    int a[10] = {};
    char s[11];
    scanf("%s", s);
    for (int k = strlen(s) - 1, i = 1; k >= 0; k--, i *= 10) {
        for (int j = 0; j < 10; j++) {
            if (s[k] == j + 48) a[j] += f(s, k) + 1 - (j ? 0 : i);
            else a[j] += f(s, k) / i * i + (s[k] > j + 48 && j ? i : 0);
        }
    }
    for (int i = 0; i < 10; i++) printf("%d ", a[i]);
}
