#include <stdio.h>

int n, arr[11], vis[11] = {0};

void bt(int *s, int len, int cur) {
    if (cur == len) {
        int rs = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] > s[i]) cnt++;
            }
            if (arr[s[i] - 1] == cnt) rs++;
        }
        if (rs == n) {
            for (int i = 0; i < n; i++) {
                printf("%d ", s[i]);
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            s[cur++] = i + 1;
            bt(s, n, cur--);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int arr1[11];
    bt(arr1, n, 0);
}
