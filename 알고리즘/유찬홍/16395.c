#include <stdio.h>

int arr[30][30];

int topDown(int n, int k) {
    if (n == k || k == 0) return 1;
    else {
        if (arr[n][k] != 0) return arr[n][k];
        arr[n][k] = topDown(n - 1, k) + topDown(n - 1, k - 1);
        return arr[n][k];
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", topDown(n - 1, k - 1));
    return 0;
}