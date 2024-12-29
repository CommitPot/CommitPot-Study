#include <stdio.h>

int main() {
    int n, sum = 0, max = 0, arr[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        max += arr[i] * arr[i - 1];
        arr[i] += arr[i - 1];
    }
    printf("%d", max);
}
