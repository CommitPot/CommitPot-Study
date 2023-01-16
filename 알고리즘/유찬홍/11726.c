#include <stdio.h>

int main() {
    int n, arr[1000] = {1, 2,};
    for (int i = 2; i <= 1000; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }
    scanf("%d", &n);
    printf("%d", arr[n - 1]);
    return 0;
}