#include <stdio.h>

int main() {
    int n, a[1000001], b[1000001];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    b[n] = -1;
    for (int i = n - 1; i; i--) {
        if (a[i] == a[i + 1]) b[i] = b[i + 1];
        else b[i] = i + 1;
    }
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
}
