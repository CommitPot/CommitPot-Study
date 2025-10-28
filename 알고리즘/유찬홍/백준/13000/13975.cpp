#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, n;
    long long r;
    cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<long long> q;
        r = 0;
        for (int i = 0, j; i < n; i++) cin >> j, q.emplace(-j);
        while (q.size() > 1) {
            auto a = q.top();
            q.pop();
            auto b = q.top();
            q.pop();
            r += -(a + b);
            q.emplace(a + b);
        }
        cout << r << '\n';
    }
}
