#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, x;
    priority_queue<int> pq;
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> x;
        if (!x) {
            if (pq.empty()) cout << 0 << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.emplace(x);
        }
    }
}
