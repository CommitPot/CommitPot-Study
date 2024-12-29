#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int n, m, r, a, b, c, rs = -1, v[101], arr[101][101];
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            arr[i][j] = 1000000000;
        }
    }
    for (int i = 0; i < r; i++) {
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = c;
        arr[b][a] = c;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = v[i];
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (m >= arr[i][j]) sum += v[j];
        }
        if (rs < sum) rs = sum;
    }
    printf("%d", rs);
}
