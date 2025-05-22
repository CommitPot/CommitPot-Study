#include <queue>
#include <cstdio>

using namespace std;

int main() {
    queue<pair<int, int> > q;
    int n, r = 0, a[1000];
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        q.emplace(j, i);
    }
    while (!q.empty()) {
        r++;
        if (q.front().first > 1) {
            q.emplace(q.front().first - 1, q.front().second);
            q.pop();
        } else a[q.front().second] = r, q.pop();
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}
