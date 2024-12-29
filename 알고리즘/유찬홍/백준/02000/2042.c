#include <stdio.h>

typedef long long int ll;
ll sum = 0, a, b, c;
long long int arr[2000001] = {0};

void find(ll s, ll e) {
    if (s % 2 == 1) sum += arr[s];
    s = (s + 1) / 2;
    if (e % 2 == 0) sum += arr[e];
    e = (e - 1) / 2;
    if (s > e) {
        printf("%lld\n", sum);
        sum = 0;
        return;
    }
    find(s, e);
}

void change(ll nod, ll val) {
    arr[nod] += val;
    if (!nod) return;
    change(nod / 2, val);
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = n + 1; i <= n * 2; i++) {
        scanf("%lld", &arr[i]);
    }
    for (int i = n * 2; i >= 0; i--) {
        arr[i / 2] += arr[i];
    }
    for (int i = 0; i < m + k; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) change(b + n, c - arr[b + n]);
        else find(b + n, c + n);
    }
}
