#include <stdio.h>

int main() {
    int n, r = 1, a[2][200001] = {}, b[400001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]), a[1][a[0][i]] = 1;
    for (int i = 0; i < n * 2; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) r &= a[0][i] == b[i];
    for (int i = 0; i < n; i++) r &= a[1][b[n + i]];
    printf("%s", r ? "YES" : "NO");
}
