#include <stdio.h>

int main() {
    int t, n, arr[12] = {1, 2, 4,};
    for (int i = 3; i < 12; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", arr[n - 1]);
    }
    return 0;
}