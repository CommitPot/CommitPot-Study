#include <stdio.h>

int main() {
    int n, m;
    long long arr[100001] = {0}, sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i - 1];
    }
    for (int i = m; i <= n; i++) {
        if (arr[i] - arr[i - m] > sum) sum = arr[i] - arr[i - m];
    }
    printf("%lld", sum);
    return 0;
}