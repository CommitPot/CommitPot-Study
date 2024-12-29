#include <stdio.h>

int main() {
    int t;
    int dx[] = {1, 1, -1, -1, 0, 0}, dy[] = {1, 0, -1, 0, 1, -1};
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, arr[15][23][23] = {0};
        scanf("%d", &n);
        arr[0][8][8] = 1;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n + 6; k++) {
                for (int l = 1; l <= n + 6; l++) {
                    for (int m = 0; m < 6; m++) {
                        if (k + dx[m] >= 0 && k + dx[m] <= n + 6 && l + dy[m] >= 0 && l + dy[m] <= n + 6) {
                            arr[j][k][l] += arr[j - 1][k + dx[m]][l + dy[m]];
                        }
                    }
                }
            }
        }
        if (n == 2) printf("6\n");
        else printf("%d\n", arr[n][8][8]);
    }
}
