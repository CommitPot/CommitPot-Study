#include <stdio.h>

int main() {
    int k, n, arr[10000], max = 0;
    long long int rs = 0;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }
    long long int s = 1, e = max;
    while (s <= e) {
        long long int mid = (s + e) / 2, c = 0;
        for (int i = 0; i < k; i++) {
            c += arr[i] / mid;
        }
        if (c < n) e = mid - 1;
        else {
            rs = mid;
            s = mid + 1;
        }
    }
    printf("%lld", rs);
    return 0;
}