#include <stdio.h>

int main() {
    int t, n, m;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int c[21], arr[10001] = {0};
        scanf("%d", &n);
        for (int j = 0; j < n; j++) scanf("%d", &c[j]);
        scanf("%d", &m);
        arr[0] = 1;
        for (int j = 0; j < n; j++) {
            for (int k = 1; k <= m; k++) {
                if (k >= c[j]) arr[k] += arr[k - c[j]];
            }
        }
        printf("%d\n", arr[m]);
    }
}
