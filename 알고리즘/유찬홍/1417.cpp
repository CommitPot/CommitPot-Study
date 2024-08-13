#include <queue>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    priority_queue<int> q;
    scanf("%d %d", &n, &m);
    for (int i = --n; i; i--) {
        scanf("%d", &n);
        q.emplace(n);
    }
    n = 0;
    while (!q.empty() && q.top() >= m) q.emplace(q.top() - 1), q.pop(), m++, n++;
    printf("%d", n);
}
