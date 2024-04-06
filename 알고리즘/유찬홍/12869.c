#include <stdio.h>
#define f(x) x > 0 ? x : 0
#define min(x, y) x > y ? y : x

const int d[6][3] = {{1, 3, 9},
                     {1, 9, 3},
                     {3, 1, 9},
                     {3, 9, 1},
                     {9, 1, 3},
                     {9, 3, 1}};
int n, l[3], dp[61][61][61];

int asdf(int x, int y, int z) {
    if (!x && !y && !z) return 1;
    if (dp[x][y][z]) return dp[x][y][z];
    dp[x][y][z] = 1e9;
    for (int i = 0; i < 6; i++) {
        dp[x][y][z] = min(dp[x][y][z], asdf(f(x - d[i][0]), f(y - d[i][1]), f(z - d[i][2])) + 1);
    }
    return dp[x][y][z];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &l[i]);
    printf("%d", asdf(l[0], l[1], l[2]) - 1);
}
