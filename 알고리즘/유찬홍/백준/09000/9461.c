#include <stdio.h>

int main() {
    int t, n;
    long long int arr[100] = {1, 1, 1,};
    for (int i = 3; i <= 100; i++) {
        arr[i] = arr[i - 2] + arr[i - 3];
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", arr[n - 1]);
    }
    return 0;
}
