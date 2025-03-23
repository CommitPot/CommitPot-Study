#include <cstdio>
#include <queue>

using namespace std;

int main() {
    long long a, r = 0;
    priority_queue<long long> q;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a);
        q.emplace(-a);
    }
    while (m--) {
        long long x = q.top();
        q.pop();
        long long y = q.top();
        q.pop();
        q.emplace(x + y);
        q.emplace(x + y);
    }
    while (!q.empty()) {
        r += q.top();
        q.pop();
    }
    printf("%lld", -r);
}
