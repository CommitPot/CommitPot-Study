#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, a;
    deque<pair<long long, int>> q;
    cin >> n >> m >> a;
    long long r = a;
    q.emplace_back(r, 0);
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (!q.empty() && i - q.front().second > m) q.pop_front();
        long long k = a + max(0ll, q.front().first);
        while (!q.empty() && q.back().first < k) q.pop_back();
        q.emplace_back(k, i);
        r = max(r, k);
    }
    cout << r;
}
