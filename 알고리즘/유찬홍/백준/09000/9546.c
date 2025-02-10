#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        int r = 1;
        while (--k) r <<= 1;
        printf("%d\n", (r << 1) - 1);
    }
}
