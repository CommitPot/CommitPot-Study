#include <stdio.h>

int main() {
    int n, k, a, b, r = 1;
    scanf("%d %d %d", &n, &k, &a);
    for (int i = 1; i < n; i++) {
        scanf("%d", &b);
        if (a + k >= b) continue;
        r++;
        a = b;
    }
    printf("%d", r);
}
