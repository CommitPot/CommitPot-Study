#include <stdio.h>

int main() {
    int h, w, l, d[][2] = {{0,  1},
                           {0,  -1},
                           {1,  1},
                           {1,  -1},
                           {1,  0},
                           {-1, 1},
                           {-1, -1},
                           {-1, 0}};
    long long r = 0, dp[2][201][201] = {};
    char m[201][201], s[101];
    scanf("%d %d %d", &h, &w, &l);
    for (int i = 0; i < h; i++) scanf("%s", m[i]);
    scanf("%s", s);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == s[0]) dp[0][i][j]++;
        }
    }
    for (int i = 1; s[i]; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (m[j][k] != s[i]) continue;
                for (int n = 0; n < 8; n++) {
                    int nj = j + d[n][0], nk = k + d[n][1];
                    if (nj < 0 || nj >= h || nk < 0 || nk >= w || m[nj][nk] != s[i - 1]) continue;
                    dp[1][j][k] += dp[0][nj][nk];
                }
            }
        }
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                dp[0][j][k] = dp[1][j][k];
                dp[1][j][k] = 0;
                if (i == l - 1) r += dp[0][j][k];
            }
        }
    }
    printf("%lld", r);
}
