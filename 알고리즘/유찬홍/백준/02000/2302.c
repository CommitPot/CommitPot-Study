#include <stdio.h>

int main() {
    int n, m, a, b = 0, rs = 1, arr[41] = {1, 1};
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        rs *= arr[a - b - 1];
        b = a;
    }
    printf("%d", rs * arr[n - b]);
}
