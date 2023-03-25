#include <stdio.h>

int main() {
    int n, k, arr[10001];
    long long int e = 0, s = 1, rs = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (e < arr[i]) e = arr[i];
    }
    while (s <= e) {
        long long int mid = (s + e) / 2, c = 0;
        for (int i = 0; i < n; i++) {
            c += arr[i] / mid;
        }
        if (c < k) e = mid - 1;
        else {
            rs = mid;
            s = mid + 1;
        }
    }
    printf("%lld", rs);
    return 0;
}