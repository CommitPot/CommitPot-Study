#include <stdio.h>
#include <memory.h>

int dp[51][51][51][51];
const int d[][3] = {{1, 0, 0},
                    {0, 1, 0},
                    {0, 0, 1},
                    {1, 1, 0},
                    {0, 1, 1},
                    {1, 0, 1},
                    {1, 1, 1}};

int f(int s, int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) return 0;
    if (!s) return !a && !b && !c;
    if (dp[s][a][b][c] >= 0) return dp[s][a][b][c];
    int e = 0;
    for (int i = 0; i < 7; i++) {
        e = (e + f(s - 1, a - d[i][0], b - d[i][1], c - d[i][2])) % 1000000007;
    }
    return dp[s][a][b][c] = e;
}

int main() {
    int s, a, b, c;
    scanf("%d %d %d %d", &s, &a, &b, &c);
    memset(dp, -1, sizeof(dp));
    printf("%d", f(s, a, b, c));
}
