#include <stdio.h>

int main() {

    int t, n, k, arr[10001];
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int arr1[10001], rs = 0;
        scanf("%d %d", &n, &k);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        arr1[0] = arr[0];
        for (int j = 1; j < n; j++) {
            if (arr[j] > arr1[rs]) arr1[++rs] = arr[j];
            else {
                int s = 0, e = rs;
                while (s < e) {
                    int mid = (s + e) / 2;
                    if (arr[j] > arr1[mid]) s = mid + 1;
                    else e = mid;
                }
                arr1[e] = arr[j];
            }
        }
        printf("Case #%d\n%d\n", i, rs + 1 >= k ? 1 : 0);
    }
    return 0;
}