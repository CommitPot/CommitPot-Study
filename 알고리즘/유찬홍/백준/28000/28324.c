#include <stdio.h>

int main() {
    int n, a[500001];
    long long r = 0;
    scanf("%d", &n);
    for (int i = n - 1; i >= 0; i--) {
        scanf("%d", &a[i]);
    }
    for (int i = 0, j = 0; i < n; i++) {
        if (j < a[i]) r += ++j;
        else r += a[i], j = a[i];
    }
    printf("%lld", r);
}
