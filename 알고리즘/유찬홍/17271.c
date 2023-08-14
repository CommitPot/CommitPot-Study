#include <stdio.h>

int main() {
    int n, m, arr[10001] = {1};
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        if (i < m) arr[i] = 1;
        else arr[i] += (arr[i - 1] + arr[i - m]) % 1000000007;
    }
    printf("%d", arr[n]);
}
