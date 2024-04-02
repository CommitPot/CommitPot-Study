#include <stdio.h>

int main() {
    long long int x, y, z;
    scanf("%lld %lld", &x, &y);
    z = y * 100 / x;
    long long int s = 1, e = 1000000001, rs;
    while (s <= e) {
        long long int m = (s + e) / 2;
        long long int l = (y + m) * 100 / (x + m);
        if (l <= z) s = m + 1;
        else e = m - 1, rs = m;
    }
    printf("%lld", s == 1e9 + 2 ? -1 : rs);
}
