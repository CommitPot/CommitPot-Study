#include <stdio.h>

int main() {
    int n, m, k;
    char a[5001002];
    scanf("%d %d %d", &n, &m, &k);
    if (n + m > ++k) n = 0;
    k = 0;
    printf("%s", n ? "YES" : "NO");
    for (int i = 0; i < n; i++) {
        a[k++] = 10;
        for (int j = 0; j < m; j++) {
            char s[5];
            int l = i + j + 1, o = 0;
            while (l) {
                s[o++] = l % 10 + 48;
                l /= 10;
            }
            while (o) a[k++] = s[--o];
            a[k++] = 32;
        }
    }
    printf("%s", a);
}
