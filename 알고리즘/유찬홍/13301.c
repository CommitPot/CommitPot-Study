#include <stdio.h>

int main() {
    int n;
    long long int arr[81] = {0, 1};
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("%lld", arr[n] * 4 + arr[n - 1] * 2);
}