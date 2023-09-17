#include <stdio.h>

int main() {
    int n, m, o, a, b;
    long long int arr[17][17] = {0};
    scanf("%d %d %d", &m, &n, &o);
    for (int i = 0; i < o; i++) {
        scanf("%d %d", &a, &b);
        arr[b][a] = -1;
    }
    arr[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == -1 || (i == 1 && j == 1)) continue;
            if (arr[i - 1][j] == -1)arr[i - 1][j] = 0;
            if (arr[i][j - 1] == -1) arr[i][j - 1] = 0;
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    printf("%lld", arr[n][m]);
}
