#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, i, a[1000];
    long long r = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for (i = 1; i < n; i++) r += a[i] - a[i - 1];
    while (a[n - 1] - a[i] <= a[i] - a[i - 1]) i++;
    printf("%lld", r + a[i] - a[0] - a[i] + a[i - 1] + a[n - 1] - a[i - 1]);
}
