#include <stdio.h>

int n, k, arr[8], vis[8] = {0}, cnt = 0;

void bt(int x, int len, int power) {
    if (power + x - k < 500) return;
    if (len == n - 1) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            power = power + x - k;
            bt(arr[i], len + 1, power);
            power = power - x + k;
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        vis[i] = 1;
        bt(arr[i], 0, 500);
        vis[i] = 0;
    }
    printf("%d", cnt);
}
