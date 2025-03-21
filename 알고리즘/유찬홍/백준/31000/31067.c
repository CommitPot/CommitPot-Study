#include <stdio.h>

int main() {
    int n, k, a, r = 0;
    scanf("%d %d %d", &n, &k, &a);
    for (int i = 1, b; i < n; i++) {
        scanf("%d", &b);
        if (a < b) {
            a = b;
            continue;
        } else if (b + k <= a) {
            r = -1;
            break;
        }
        a = b + k;
        r++;
    }
    printf("%d", r);
}
