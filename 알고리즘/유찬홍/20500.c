#include <stdio.h>

int main() {
    int n, arr[1516] = {0};
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        arr[i] = i % 2 == 1 ? arr[i - 1] * 2 - 1 : arr[i - 1] * 2 + 1;
        arr[i] %= 1000000007;
    }
    printf("%d", arr[n]);
}
