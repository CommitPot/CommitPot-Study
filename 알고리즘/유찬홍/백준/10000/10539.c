#include <stdio.h>

int main() {
    int n, arr[101], arr1[101] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        arr1[i] = arr[i] * i;
        arr1[i] -= sum;
        sum += arr1[i];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr1[i]);
    }
}
