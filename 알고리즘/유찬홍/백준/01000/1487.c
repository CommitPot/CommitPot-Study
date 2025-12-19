#include <stdio.h>

int main() {
    int n, a[50], b[50], r = 0, v = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] >= a[i] && a[i] > b[j]) k += a[i] - b[j];
        }
        if (v <= k) {
            r = v < k ? a[i] : r < a[i] ? r : a[i];
            v = k;
        }
    }
    printf("%d", r);
}
