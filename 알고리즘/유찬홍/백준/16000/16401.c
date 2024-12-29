#include <stdio.h>

int main() {
    int m, n, arr[1000000], max = 0, rs = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }
    int s = 1, e = max;
    while (s <= e) {
        int mid = (s + e) / 2, c = 0;
        for (int i = 0; i < n; i++) {
            c += arr[i] / mid;
        }
        if (c < m) e = mid - 1;
        else {
            rs = mid;
            s = mid + 1;
        }
    }
    printf("%d", rs);
    return 0;
}