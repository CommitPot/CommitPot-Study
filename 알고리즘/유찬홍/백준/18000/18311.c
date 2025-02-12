#include <stdio.h>

int main() {
    int n, a[100001];
    char s[600001];
    long long k;
    scanf("%d %lld ", &n, &k);
    scanf("%[^\n]", s);
    for (int i = 0, j = 1; s[i]; i++) {
        int v = 0;
        while (s[i] > 47) v = v * 10 + s[i++] - 48;
        a[j++] = v;
    }
    for (int i = 1; i <= n * 2; i++) {
        k -= a[i > n ? n * 2 - i + 1 : i];
        if (k < 0) {
            printf("%d", i > n ? n * 2 - i + 1 : i);
            break;
        }
    }
}
