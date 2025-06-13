#include <stdio.h>

int main() {
    int n, k, p, a[51], r = 0;
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 0; i < n * k; i++) {
        scanf("%d", &a[i % k]);
        if (i % k == k - 1) {
            int w = 0;
            for (int j = 0; j < k; j++) w += !a[j];
            if (w < p) r++;
        }
    }
    printf("%d", r);
}
