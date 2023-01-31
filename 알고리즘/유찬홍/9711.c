#include <stdio.h>

int main() {
    int t, a, b;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        long long int arr[10001] = {0, 1};
        scanf("%d %d", &a, &b);
        for (int j = 2; j <= a; j++) {
            arr[j] = (arr[j - 1] + arr[j - 2]) % b;
        }
        printf("Case #%d: %lld\n", i, arr[a] % b);
    }
    return 0;
}