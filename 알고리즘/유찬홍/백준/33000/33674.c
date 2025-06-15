#include <stdio.h>

int main() {
    int n, d, k, a, b = 0, c = 0, r = 0;
    scanf("%d %d %d", &n, &d, &k);
    while (n--) {
        scanf("%d", &a);
        if (b < a) b = a;
    }
    while (d--) {
        c += b;
        if (c > k) c = b, r++;
    }
    printf("%d", r);
}
