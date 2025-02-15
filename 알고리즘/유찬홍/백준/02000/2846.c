#include <stdio.h>

int main() {
    int n, a, r = 0, k = 0;
    scanf("%d %d", &n, &a);
    for (int i = 1, j; i < n; i++) {
        scanf("%d", &j);
        if (j > a) k += j - a;
        else r = r < k ? k : r, k = 0;
        a = j;
    }
    printf("%d", r < k ? k : r);
}
