#include <stdio.h>

int main() {
    int n, k, s = 0, c = -20000001, sum = 0, arr[100000] = {0};
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < k; i++) sum += arr[i];
    while (s <= n - k) {
        if (sum > c) c = sum;
        sum = sum - arr[s] + arr[s++ + k];
    }
    printf("%d", c);
}