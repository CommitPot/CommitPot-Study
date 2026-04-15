#include <stdio.h>

int main() {
    int n, m, c[26] = {}, l;
    char a[101], b[101];
    scanf("%d %s %d %s", &n, a, &m, b);
    for (int i = 0; a[i]; i++) c[a[i] - 97]++;
    for (int i = 0; b[i]; i++) {
        if (!c[b[i] - 97]) {
            printf("-1");
            return 0;
        }
    }
    l = n - 1;
    for (int i = 0; b[i]; i++) {
        while (a[++l % n] != b[i]);
    }
    printf("%d", l - n + 1);
}
