#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a[10001];
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            r += abs(a[i] - a[j]);
        }
    }
    printf("%lld", r);
}
