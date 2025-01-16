#include <stdio.h>

int main() {
    int n, x, k, a, b;
    scanf("%d %d %d", &n, &x, &k);
    while (k--) {
        scanf("%d %d", &a, &b);
        if (x == a) x = b;
        else if (x == b) x = a;
    }
    printf("%d", x);
}
