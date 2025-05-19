#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n, m, r;
    cin >> t;
    while (t--) {
        r = 0;
        cin >> n >> m;
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        for (int i = 0, a; i < n; i++) cin >> a, q.emplace(i, a), pq.push(a);
        while (true) {
            if (q.front().second < pq.top()) {
                q.push(q.front());
                q.pop();
            } else {
                r++;
                if (q.front().first == m) break;
                pq.pop();
                q.pop();
            }
        }
        cout << r << '\n';
    }
}
