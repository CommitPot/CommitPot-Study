#include <stdio.h>

int main() {
    int n, arr[51] = {1, 1};
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        arr[i] = (1 + arr[i - 1] + arr[i - 2]) % 1000000007;
    }
    printf("%d", arr[n]);
    return 0;
}