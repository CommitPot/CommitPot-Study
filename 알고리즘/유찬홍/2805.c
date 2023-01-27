#include <stdio.h>

int main() {
    int n, m, arr[1000000], max = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }
    int j = 0, k = max - 1, rs;
    while (j <= k) {
        int mid = (j + k) / 2;
        long long int l = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) l += arr[i] - mid;
        }
        if (l < m) k = mid - 1;
        else {
            rs = mid;
            j = mid + 1;
        }
    }
    printf("%d", rs);
    return 0;
}