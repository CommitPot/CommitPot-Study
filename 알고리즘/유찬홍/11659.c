#include <stdio.h>

int main() {
    int n, m, a, b, arr[100001] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", arr[b] - arr[a - 1]);
    }
}