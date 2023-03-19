#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, arr[10000], max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }
    scanf("%d", &m);
    int s = 0, e = max, rs = 0;
    while (s <= e) {
        int mid = (s + e) / 2, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i] - mid < 0 ? arr[i] : mid;
        }
        if (sum > m) e = mid - 1;
        else {
            if (rs < mid) rs = mid;
            s = mid + 1;
        }
    }
    printf("%d", rs);
    return 0;
}