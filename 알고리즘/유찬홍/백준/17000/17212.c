#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n, arr[100001] = {0, 1, 1, 2, 2, 1, 2, 1};
    scanf("%d", &n);
    for (int i = 8; i <= n; i++) {
        arr[i] = min(arr[i - 1] + 1, arr[i - 2] + 1);
        arr[i] = min(arr[i], arr[i - 5] + 1);
        arr[i] = min(arr[i], arr[i - 7] + 1);
    }
    printf("%d", arr[n]);
}
