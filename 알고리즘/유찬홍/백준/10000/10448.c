#include <stdio.h>

int main() {
    int t, n, a[44] = {}, r[2971] = {};
    for (int i = 1, j = 1; i < 1e3; i += j) a[j - 1] = i, j++;
    for (int i = 0; i < 44; i++) {
        for (int j = 0; j < 44; j++) {
            for (int k = 0; k < 44; k++) {
                r[a[i] + a[j] + a[k]] = 1;
            }
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", r[n]);
    }
}
