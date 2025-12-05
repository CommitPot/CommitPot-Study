#include <math.h>
#include <stdio.h>

int main() {
    int n;
    long long a[300001], r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    r = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < r) r = (long long) ceil((double) r / a[i]) * a[i];
        else r = a[i];
    }
    printf("%lld", r);
}
