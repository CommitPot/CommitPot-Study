#include <stdio.h>

int main() {
    int t, n, zero, one, arr[41] = {0, 1};
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        for (int j = 2; j <= n; j++) {
            arr[j] = arr[j - 1] + arr[j - 2];
        }
        zero = n == 0 ? 1 : arr[n - 1];
        one = arr[n];
        printf("%d %d\n", zero, one);
    }
    return 0;
}
