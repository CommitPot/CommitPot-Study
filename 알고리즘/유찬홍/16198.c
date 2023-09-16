#include <stdio.h>

int n, arr[11], vis[11] = {0}, rs = 0;

void bt(int len, int sum) {
    if (len == n - 2) {
        if (rs < sum) rs = sum;
        return;
    }
    for (int i = 2; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            int j = i - 1;
            for (; vis[j]; j--);
            int k = i + 1;
            for (; vis[k]; k++);
            bt(len + 1, sum + arr[j] * arr[k]);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    bt(0, 0);
    printf("%d", rs);
}
