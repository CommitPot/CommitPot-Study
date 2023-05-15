#include <stdio.h>

int main() {
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        int arr[1001] = {0}, max = -100000001;
        for (int j = 1; j <= a; j++) {
            scanf("%d", &arr[j]);
            if (arr[j - 1] >= 0) arr[j] += arr[j - 1];
        }
        for (int j = 1; j <= a; j++) {
            if (max < arr[j]) max = arr[j];
        }
        printf("%d\n", max);
    }
}
