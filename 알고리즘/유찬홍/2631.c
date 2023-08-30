#include <stdio.h>

int main() {
    int n, rs = 0, arr[201], bs[201];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    bs[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (bs[rs] < arr[i]) bs[++rs] = arr[i];
        else {
            int s = 0, e = rs;
            while (s < e) {
                int mid = (s + e) / 2;
                if (bs[mid] < arr[i]) s = mid + 1;
                else e = mid;
            }
            bs[e] = arr[i];
        }
    }
    printf("%d", n - rs - 1);
}
