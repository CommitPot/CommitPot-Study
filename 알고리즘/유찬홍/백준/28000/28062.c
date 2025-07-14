#include <stdio.h>

int main() {
    int n, r = 0, f = 1e9;
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        r += j;
        if (j & 1 && f > j) f = j;
    }
    printf("%d", r & 1 ? r - f : r);
}
