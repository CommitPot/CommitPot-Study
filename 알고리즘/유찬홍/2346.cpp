#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    deque<pair<int, int>> dq;
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        dq.emplace_back(i, a);
    }
    while (!dq.empty()) {
        int f = dq.front().first;
        int s = dq.front().second;
        dq.pop_front();
        cout << f << " ";
        if (s > 0) {
            s--;
            while (s--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            while (s++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}
