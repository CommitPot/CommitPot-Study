#include <stdio.h>

int main() {
    int n, arr[100001] = {0};
    long long int ans = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    for (int i = 1; i <= n; i++) {
        sum -= arr[i];
        ans += arr[i] * sum;
    }
    printf("%lld", ans);
}
