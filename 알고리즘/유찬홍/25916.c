#include <stdio.h>

int main() {
    int n, m, arr[500001] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    int j = 0, k = 0, sum = 0, count = 0;
    while (k <= n) {
        if (sum > m) {
            if (j == k) sum = arr[++j], k++;
            else sum -= arr[++j];
        } else {
            if (sum > count) count = sum;
            sum += arr[++k];
        }
    }
    printf("%d", count);
}