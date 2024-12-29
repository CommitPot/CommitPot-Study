#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int a, k, arr[2000002] = {0};
    for (int i = 0; i < 1000001; i++) {
        arr[i] = 1000000000;
    }
    scanf("%d %d", &a, &k);
    arr[a] = 0;
    for (int i = a; i <= k; i++) {
        arr[i * 2] = min(arr[i * 2], arr[i] + 1);
        arr[i + 1] = min(arr[i + 1], arr[i] + 1);
    }
    printf("%d", arr[k]);
}