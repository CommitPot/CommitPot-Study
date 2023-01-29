#include <stdio.h>

int main() {
    int n, k, count = 0, p = 1000001, arr[1000000];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < k; i++) if (arr[i] == 1) count++;
    int s = 0, e = k - 1;
    while (e <= n) {
        if (count < k) {
            if (arr[++e] == 1) count++;
        } else {
            if (p > e - s + 1) p = e - s + 1;
            if (arr[s++] == 1) count--;
        }
    }
    printf("%d", p == 1000001 ? -1 : p);
    return 0;
}