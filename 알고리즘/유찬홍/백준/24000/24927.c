#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        while (~j & 1) j >>= 1, k--;
    }
    printf("%d", k <= 0);
}
