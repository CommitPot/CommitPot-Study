#include <stdio.h>

int main() {
    int n;
    long long int arr[100] = {1};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int j = 0, k = i - 1; j < i; j++, k--) {
            sum += arr[j] * arr[k];
        }
        arr[i] = sum;
    }
    printf("%lld", arr[n]);
    return 0;
}