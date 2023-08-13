#include <stdio.h>
#include <stdlib.h>

int n, arr[8], vis[8] = {0}, rs = 0;

void bt(int *arr1, int len) {
    if (len == n) {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(arr1[i] - arr1[i + 1]);
        }
        if (rs < sum) rs = sum;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            arr1[len++] = arr[i];
            bt(arr1, len--);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int arr1[8];
    bt(arr1, 0);
    printf("%d", rs);
}
