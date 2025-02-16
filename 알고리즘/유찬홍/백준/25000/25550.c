#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n, m, a[1000][1000];
    long long r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = n - 2; i > 0; i--) {
        for (int j = m - 2; j > 0; j--) {
            if (!a[i][j]) continue;
            int k = min(min(a[i][j - 1], a[i][j + 1]), min(a[i - 1][j], a[i + 1][j]));
            r += k < a[i][j] ? k : a[i][j] - 1;
        }
    }
    printf("%lld", r);
}
