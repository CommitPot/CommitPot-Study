#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int s, b;
} element;
int n, vis[11] = {0}, rs = 1000000000;
element arr[11];

void bt(int sum1, int sum2) {
    if (rs > abs(sum1 - sum2) && sum2) rs = abs(sum1 - sum2);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            bt(sum1 * arr[i].s, sum2 + arr[i].b);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].s, &arr[i].b);
    }
    bt(1, 0);
    printf("%d", rs);
}
