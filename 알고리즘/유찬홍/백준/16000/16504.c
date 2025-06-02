#include <stdio.h>

int main() {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0, k; j < n; j++) {
            scanf("%d", &k);
            r += k;
        }
    }
    printf("%lld", r);
}
