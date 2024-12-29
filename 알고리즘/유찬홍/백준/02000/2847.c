#include <stdio.h>

int main() {
    int n, arr[101], count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        if (arr[i] <= arr[i - 1]) {
            count += arr[i - 1] - arr[i] + 1;
            arr[i - 1] -= arr[i - 1] - arr[i] + 1;
        }
    }
    printf("%d", count);
}
