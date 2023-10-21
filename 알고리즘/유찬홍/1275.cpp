#include <cstdio>

long long int arr[400001], sum = 0;

void find(int s, int e) {
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

void change(int node, int d) {
    arr[node] = d;
    while (node >= 1) {
        node /= 2;
        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }
}

int main() {
    int a, b, c, d, n, m;
    scanf("%d %d", &n, &m);
    for (int i = n + 1; i <= n * 2; i++) scanf("%lld", &arr[i]);
    for (int i = n * 2; i >= 1; i--) {
        arr[i / 2] += arr[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        find(a < b ? a + n : b + n, a < b ? b + n : a + n);
        change(c + n, d);
    }
}
