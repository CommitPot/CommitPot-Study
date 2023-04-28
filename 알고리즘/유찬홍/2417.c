#include <stdio.h>
#include <math.h>

int main() {
    long long int n, rs;
    scanf("%lld", &n);
    long long int s = 0, e = n;
    while (s <= e) {
        long long int mid = (s + e) / 2;
        if (pow((double) mid, 2) < (double) n) {
            s = mid + 1;
        } else {
            e = mid - 1;
            rs = mid;
        }
    }
    printf("%lld", rs);
}
