#include <stdio.h>

int main() {
    int n, arr[1001];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] < arr[j] + arr[i - j]) arr[i] = arr[j] + arr[i - j];
        }
    }
    printf("%d", arr[n]);
}
