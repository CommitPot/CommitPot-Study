#include <stdio.h>

int main() {
    int t, n;
    long long int arr[1000000] = {1, 2, 4,};
    for (int i = 3; i < 1000001; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % 1000000009;
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", arr[n - 1]);
    }
    return 0;
}