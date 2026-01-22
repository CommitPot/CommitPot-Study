#include <stdio.h>

int main() {
    int n, k = 1, r = 0;
    scanf("%d", &n);
    while (n) {
        if (n < k) k = 1;
        n -= k++;
        r++;
    }
    printf("%d", r);
}
