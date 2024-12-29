#include <stdio.h>

int main() {
    int n, k, rs = 0, arr[200000], arr1[200000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    arr1[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr1[rs]) arr1[++rs] = arr[i];
        else {
            int s = 0, e = rs;
            while (s < e) {
                int m = (s + e) / 2;
                if (arr[i] > arr1[m]) s = m + 1;
                else e = m;
            }
            arr1[e] = arr[i];
        }
    }
    printf("%d", n - rs - 1);
    return 0;
}