#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int n, a, b, arr[1000001] = {0};
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i > b) {
            arr[i] = min(arr[i - b - 1] + 1, arr[i]);
        }
        if (i > a) {
            arr[i] = min(arr[i - a - 1] + 1, arr[i]);
        }
    }
    printf("%d", arr[n]);
}
