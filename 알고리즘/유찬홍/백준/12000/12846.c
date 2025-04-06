#include <stdio.h>

int main() {
    int n, s[100001][2], t = 0;
    s[0][0] = s[0][1] = 0;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        while (t && s[t][0] > a) {
            int k = s[t][0], f = s[t][1];
            int f1 = s[t - 1][1];
            r = r < (long long) k * (i - f1 - 1) ? (long long) k * (i - f1 - 1) : r;
            t--;
        }
        if (s[t][0] == a) s[t][1] = i;
        else {
            t++;
            s[t][0] = a, s[t][1] = i;
        }
    }
    while (t) {
        int k = s[t][0], f = s[t][1];
        int f1 = s[t - 1][1];
        r = r < (long long) k * (n - f1) ? (long long) k * (n - f1) : r;
        t--;
    }
    printf("%lld", r);
}
