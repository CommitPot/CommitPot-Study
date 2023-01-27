#include <stdio.h>

int main() {
    int n, m, a, k, arr[20000001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        arr[k + 10000000]++;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        printf("%d ", arr[a + 10000000] > 0 ? arr[a + 10000000] : 0);
    }
}