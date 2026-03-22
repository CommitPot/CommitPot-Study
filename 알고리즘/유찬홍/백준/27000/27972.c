#include <stdio.h>

int main() {
    int n, a, r = 0;
    scanf("%d %d", &n, &a);
    for (int i = 1, b, k = 0, w = 0; i < n; i++) {
        scanf("%d", &b);
        if (a == b) continue;
        if (a < b ^ k > 0) w = 1, k = k > 0 ? -1 : 1;
        else w++;
        r = r < w ? w : r;
        a = b;
    }
    printf("%d", ++r);
}
