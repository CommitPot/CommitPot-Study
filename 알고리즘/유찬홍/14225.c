#include <stdio.h>

int n, vis[2000001], d[21];

void func(int sum, int c) {
    if (c > n) return;
    vis[sum]++;
    func(sum + d[c], c + 1);
    func(sum, c + 1);
}

int main() {
    int rs = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    func(0, 0);
    while (vis[rs]) rs++;
    printf("%d", rs);
}
