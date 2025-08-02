#include <stdio.h>

int main() {
    int n, a[63] = {}, r = 62;
    long long p = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long int j;
        int k = -1;
        scanf("%lld", &j);
        while (j) {
            j /= 2;
            k++;
        }
        if (k < 0) continue;
        a[k]++;
    }
    for (int i = 0; i < 63; i++) a[i + 1] += a[i] / 2;
    while (!a[r]) r--;
    while (r--) p *= 2;
    printf("%lld", p);
}
