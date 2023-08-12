#include <stdio.h>

int main() {
    int n, m, a, b, c, arr[100001] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);
        arr[i] = arr[i - 1] + c;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", arr[b + 1] - arr[a]);
    }
}
