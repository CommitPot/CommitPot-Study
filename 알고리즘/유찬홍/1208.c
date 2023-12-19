#include <stdio.h>
#include <stdlib.h>

int n, s, d[41], e = 1e6 * 4, m[8000002];
long long int rs = 0;

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void bt(int sum, int st, int en) {
    if (st == en) {
        if (en == n) rs += m[e + s - sum];
        else m[e + sum]++;
        return;
    }
    bt(sum, st + 1, en);
    bt(sum + d[st], st + 1, en);
}


int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    qsort(d, n, 4, comp);
    bt(0, 0, n / 2);
    bt(0, n / 2, n);
    printf("%lld", !s ? rs - 1 : rs);
}
