#include <stdio.h>

int main() {
    int n, k, arr[20];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d,", &arr[i]);
    }
    scanf("%d", &arr[n - 1]);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            arr[j] = arr[j + 1] - arr[j];
        }
    }
    for (int i = 0; i < n - k - 1; i++) {
        printf("%d,", arr[i]);
    }
    printf("%d", arr[n - k - 1]);
}
