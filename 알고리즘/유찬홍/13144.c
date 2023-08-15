#include <stdio.h>

int main() {
    int n, arr[100001], vis[100001] = {0};
    long long int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int s = 0, e = 0;
    while (s <= e) {
        if (!vis[arr[e]] && e < n) vis[arr[e++]]++;
        else {
            cnt += e - s;
            vis[arr[s++]]--;
        }
    }
    printf("%lld", cnt);
}
