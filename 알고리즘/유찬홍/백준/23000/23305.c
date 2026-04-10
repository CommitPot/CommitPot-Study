#include <stdio.h>

int main() {
    int n, a[1000001] = {}, r[2] = {};
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) scanf("%d", &j), a[j]++;
    for (int i = 0, j; i < n; i++) scanf("%d", &j), a[j]--;
    for (int i = 0; i < 1000001; i++) r[0] += a[i] > 0 ? a[i] : 0, r[1] += a[i] < 0 ? -a[i] : 0;
    printf("%d", r[0] < r[1] ? r[1] : r[0]);
}
