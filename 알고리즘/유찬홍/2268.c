#include <stdio.h>

#define ll long long int
ll rs = 0, arr[4000001] = {0};

void sum(ll s, ll e) {
    if (s % 2 == 1) rs += arr[s];
    s = (s + 1) / 2;
    if (e % 2 == 0) rs += arr[e];
    e = (e - 1) / 2;
    if (s > e) {
        printf("%lld\n", rs);
        rs = 0;
        return;
    }
    sum(s, e);
}


void modify(ll nod, ll val) {
    arr[nod] += val;
    if (!nod) return;
    modify(nod / 2, val);
}


int main() {
    int a, b, c, n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (!a) {
            if (b < c) sum(b + n, c + n);
            else sum(c + n, b + n);
        } else modify(b + n, c - arr[b + n]);
    }
}
