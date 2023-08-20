#include <stdio.h>

int arr[10], vis[10] = {0}, a, b, c = 0;

void bt(int v, int len, int cur) {
    if (cur == len) {
        if (b > v && c < v) c = v;
        return;
    }
    for (int i = 0; i < len; i++) {
        if (!cur && !arr[i]) continue;
        if (!vis[i]) {
            vis[i] = 1;
            v = v * 10 + arr[i];
            bt(v, len, cur + 1);
            v /= 10;
            vis[i] = 0;
        }
    }
}

int main() {
    int d = 0;
    scanf("%d %d", &a, &b);
    while (a > 0) {
        int e = a % 10;
        arr[d++] = e;
        a /= 10;
    }
    bt(0, d, 0);
    printf("%d", !c ? -1 : c);
}
