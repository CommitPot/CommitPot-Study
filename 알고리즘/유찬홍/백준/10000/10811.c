#include <stdio.h>

int main() {
    int n, m, a, b, arr[101];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        for (int j = a, k = b; j - k < 1; j++, k--) {
            int w = arr[j];
            arr[j] = arr[k];
            arr[k] = w;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}