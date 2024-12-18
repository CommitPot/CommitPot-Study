#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, a[100001];
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        int t = a[i] - a[i] / 10, s = 0, e = i;
        while (s < e) {
            int m = (s + e) / 2;
            if (a[m] < t) s = m + 1;
            else e = m;
        }
        r += i - e;
    }
    printf("%lld", r);
}
