#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int n, m, arr[10], vis[10] = {0}, prime[10000], cnt = 0, pv[1000000] = {0};

void bt(int len, int sum) {
    if (len == m) {
        for (int i = 2; i < sum; i++) {
            if (sum % i == 0) return;
        }
        if (!pv[sum]) {
            pv[sum]++;
            prime[cnt++] = sum;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            bt(len + 1, sum + arr[i]);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bt(0, 0);
    qsort(prime, cnt, 4, comp);
    if (!cnt) {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < cnt; i++) {
        printf("%d ", prime[i]);
    }
}
