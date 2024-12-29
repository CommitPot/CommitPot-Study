#include <stdio.h>

int main() {
    int n, arr[100000], lcs[100000];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        lcs[0] = arr[0];
        int rs = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > lcs[rs]) lcs[++rs] = arr[i];
            else {
                int s = 0, e = rs;
                while (s < e) {
                    int mid = (s + e) / 2;
                    if (arr[i] > lcs[mid]) s = mid + 1;
                    else e = mid;
                }
                lcs[e] = arr[i];
            }
        }
        printf("%d\n", rs + 1);
    }
    return 0;
}