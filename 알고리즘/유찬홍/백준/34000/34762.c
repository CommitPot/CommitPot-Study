#include <stdio.h>

int main() {
    int n, m, k, a, b;
    scanf("%d %d %d %d", &n, &k, &m, &a);
    for (int i = 1; i < m; i++) {
        scanf("%d", &b);
        if (b - a > 1 && b - a < k + 2) {
            printf("NO");
            return 0;
        }
        a = b;
    }
    printf("%s", n != a && n - a < k + 1 ? "NO" : "YES");
}
