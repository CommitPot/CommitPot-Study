#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<pair<int, int>> heapq;
    int n, m;
    cin >> n;
    while (n--) {
        cin >> m;
        if (!m) {
            if (heapq.empty()) cout << "0" << "\n";
            else {
                cout << -heapq.top().second << "\n";
                heapq.pop();
            }
        } else {
            heapq.emplace(-std::abs(m), -m);
        }
    }
}
