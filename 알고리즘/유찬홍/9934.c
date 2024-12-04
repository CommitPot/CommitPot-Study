#include <stdio.h>

int main() {
    int n, a[1025];
    scanf("%d", &n);
    n = 1 << n;
    for (int i = 1; i < n; i++) scanf("%d", &a[i]);
    for (int i = n; i >= 2; i >>= 1) {
        for (int j = i / 2; j < n; j += i) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}
