#include <stdio.h>
#include <string.h>

int main() {
    int n, r = 0, w = 0;
    char a[21], b[21];
    scanf("%d", &n);
    for (int i = 0, k, m; i < n; i++) {
        int c = 0;
        scanf("%s %d %d", a, &k, &m);
        while (k <= m) {
            m -= k;
            m += 2;
            c++;
        }
        if (w < c) w = c, strcpy(b, a);
        r += c;
    }
    printf("%d\n%s", r, b);
}
