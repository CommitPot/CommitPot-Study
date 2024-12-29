#include <stdio.h>

int main() {
    int n, arr[100001];
    scanf("%d", &n);
    arr[0] = 1;
    arr[1] = 3;
    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i - 1] * 2 + arr[i - 2]) % 9901;
    }
    printf("%d", arr[n]);
}
