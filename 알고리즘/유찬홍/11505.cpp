#include <cstdio>

typedef long long int ll;
int a, b, c, n, m, k, mod = 1e9 + 7;
ll arr[4000001], sum = 1;

void find(int s, int e) {
    if (s % 2 == 1) sum = (sum % mod * arr[s] % mod) % mod;
    s = (s + 1) / 2;
    if (e % 2 == 0) sum = (sum % mod * arr[e] % mod) % mod;
    e = (e - 1) / 2;
    if (s > e) {
        printf("%lld\n", sum);
        sum = 1;
        return;
    }
    find(s, e);
}

void change(int node, int d) {
    arr[node] = d;
    while (node >= 1) {
        node /= 2;
        arr[node] = (arr[node * 2] % mod) * (arr[node * 2 + 1] % mod) % mod;
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = n + 1; i <= n * 2; i++) {
        scanf("%lld", &arr[i]);
        arr[i - n] = 1;
    }
    arr[n * 2 + 1] = 1;
    for (int i = n * 2; i >= 1; i--) {
        arr[i / 2] = (arr[i / 2] * arr[i]) % mod;
    }
    for (int i = 0; i < m + k; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) change(b + n, c);
        else find(b + n, c + n);
    }
}
