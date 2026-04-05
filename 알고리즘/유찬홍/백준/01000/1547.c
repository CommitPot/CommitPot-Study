#include <stdio.h>

int main() {
    int n, a, b, r = 1;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        r = a == r ? b : b == r ? a : r;
    }
    printf("%d", r);
}
