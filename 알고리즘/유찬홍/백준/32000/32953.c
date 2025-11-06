#include <stdio.h>

int n, m, a[10000001] = {}, r = 0;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0, o; i < n; i++) {
        scanf("%d", &o);
        for (int j = 0, k; j < o; j++) {
            scanf("%d", &k);
            a[k % 10000000]++;
        }
    }
    for (int i = 0; i < 10000001; i++) r += a[i] >= m;
    printf("%d", r);
}
