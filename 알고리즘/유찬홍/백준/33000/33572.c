#include <stdio.h>

int main() {
    int n;
    long long m, k, r = 0;
    scanf("%d %lld", &n, &m);
    for (int i = 0; i < n; i++) scanf("%lld", &k), r += k - 1;
    printf("%s", r < m ? "OUT" : "DIMI");
}
