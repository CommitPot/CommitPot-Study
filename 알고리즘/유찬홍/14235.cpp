#include <cstdio>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> q;
    int n;
    scanf("%d", &n);
    for (int i = 0, a, b; i < n; i++) {
        scanf("%d", &a);
        if (a) {
            while (a--) {
                scanf("%d", &b);
                q.emplace(b);
            }
        } else {
            if (q.empty()) printf("-1\n");
            else printf("%d\n", q.top()), q.pop();
        }
    }
}
