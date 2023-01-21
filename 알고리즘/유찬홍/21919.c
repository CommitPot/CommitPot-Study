#include <stdio.h>

int main() {
    int n, arr[10001], prime[1000001] = {0};
    long long int sum = 0;
    for (int i = 2; i <= 1000; i++) {
        if (!prime[i]) {
            for (int j = i * 2; j <= 1000000; j += i) {
                prime[j] = 1;
            }
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (!prime[arr[i]]) {
            if (sum == 0) sum = arr[i];
            else {
                if (sum % arr[i] != 0) sum *= arr[i];
            }
        }
    }
    printf("%lld", sum == 0 ? -1 : sum);
}