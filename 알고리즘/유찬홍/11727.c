#include <stdio.h>

int main() {
    int n, arr[1000] = {1, 1};
    for (int i = 2; i <= 1000; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
    }
    scanf("%d", &n);
    printf("%d", arr[n]);
    return 0;
}