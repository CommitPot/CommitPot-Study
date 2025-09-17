#include <stdio.h>

int main() {
    int n, x, r = 0;
    scanf("%d %d", &n, &x);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        r += a;
    }
    printf("%d", !(r % x));
}
