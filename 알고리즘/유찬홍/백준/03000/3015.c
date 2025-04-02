#include <stdio.h>

long long f(int x) { return x * (long long) (x - 1) / 2; }

int main() {
    int n, q[500001][2], t = 0;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        while (t && q[t - 1][0] < a) {
            r += q[t - 1][1] * ((t > 1) + 1);
            r += f(q[--t][1]);
        }
        if (t && q[t - 1][0] == a) q[t - 1][1]++;
        else q[t][1] = 1, q[t++][0] = a;
    }
    for (int i = 1; i < t; i++) {
        r += q[i][1] + f(q[i][1]);
    }
    printf("%lld", r + f(q[0][1]));
}
