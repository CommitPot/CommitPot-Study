#include <stdio.h>

int cnt = 0, n, vis[10] = {0};
long long int rs = -1;

void bt(long long int x, int len, int c) {
    if (cnt == n) return;
    if (len == c) {
        cnt++;
        if (cnt == n) rs = x;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (!vis[i] && i < x % 10) {
            vis[i] = 1;
            bt(x * 10 + i, len + 1, c);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 9; j++) {
            bt(j, 1, i);
        }
    }
    printf("%lld", !n ? 0 : rs);
}
