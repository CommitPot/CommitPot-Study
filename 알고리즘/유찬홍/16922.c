#include <stdio.h>

int n, c, vis[1001], a[] = {1, 5, 10, 50};

void dfs(int v, int idx, int len) {
    if (len == n) {
        if (!vis[v]) vis[v]++, c++;
        return;
    }
    for (int i = idx; i < 4; i++) {
        dfs(v + a[i], i, len + 1);
    }
}

int main() {
    scanf("%d", &n);
    dfs(0, 0, 0);
    printf("%d", c);
    return 0;
}
