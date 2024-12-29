#include <stdio.h>

int arr[10000001] = {1, 1};
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
    }
    printf("%d", arr[n]);
}
