#include <stdio.h>

int main() {
    int h, n, s, m;
    long long int arr[31][31] = {0};
    scanf("%d %d", &h, &n);
    s = (h < n ? h : n) + 1;
    m = h > n ? h : n;
    for (int i = s; i <= m; i++) arr[s][i] = 1;
    for (int i = s; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1];
        }
    }
    printf("%lld", h == n ? 1 : arr[m][m]);
}
