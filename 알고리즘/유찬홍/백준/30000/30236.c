#include <stdio.h>

int main() {
    int n, t, k, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        r = 0;
        while (n--) {
            scanf("%d", &k);
            while (++r == k);
        }
        printf("%d\n", r);
    }
}
