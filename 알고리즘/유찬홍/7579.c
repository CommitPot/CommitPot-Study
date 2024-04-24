#include <stdio.h>

#define f(i, v, n) for (int i = v; i <= n; i++)

int main() {
    int n, m, r = 1e5, w[101], v[101], b[10001] = {};
    scanf("%d %d", &n, &m);
    f(i, 1, n) scanf("%d", &v[i]);
    f(i, 1, n) scanf("%d", &w[i]);
    f(i, 1, n) {
        for (int j = 10000; j >= w[i]; j--) {
            if (b[j] < b[j - w[i]] + v[i]) b[j] = b[j - w[i]] + v[i];
        }
    }
    f(i, 0, 10000) {
        if (b[i] >= m) {
            printf("%d", i);
            break;
        }
    }
}
