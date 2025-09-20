#include <deque>
#include <cstdio>

using namespace std;

int main() {
    deque<int> q;
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i < n; i++) q.emplace_back(i + 1);
    while (q.size()) {
        for (int i = 0; i < m && q.size(); i++) {
            for (int j = 1; j < k; j++) {
                q.emplace_back(q.front());
                q.pop_front();
            }
            printf("%d\n", q.front());
            q.pop_front();
        }
        for (int i = 0; i < m && q.size(); i++) {
            for (int j = 1; j < k; j++) {
                q.emplace_front(q.back());
                q.pop_back();
            }
            printf("%d\n", q.back());
            q.pop_back();
        }
    }
}
