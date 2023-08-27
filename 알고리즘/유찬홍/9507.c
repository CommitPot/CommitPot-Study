#include <stdio.h>

int main() {
    long long int arr[68] = {1, 1, 2, 4};
    int t, n;
    for (int i = 4; i <= 67; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }
}
