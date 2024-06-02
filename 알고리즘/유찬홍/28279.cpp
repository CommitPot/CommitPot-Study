#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    deque<int> dq;
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            dq.emplace_front(b);
        }
        if (a == 2) {
            cin >> b;
            dq.emplace_back(b);
        }
        if (a == 3) {
            if (dq.empty()) cout << -1;
            else {
                cout << dq.front();
                dq.pop_front();
            }
        }
        if (a == 4) {
            if (dq.empty()) cout << -1;
            else {
                cout << dq.back();
                dq.pop_back();
            }
        }
        if (a == 5) cout << dq.size();
        if (a == 6) cout << dq.empty();
        if (a == 7) cout << (dq.empty() ? -1 : dq.front());
        if (a == 8) cout << (dq.empty() ? -1 : dq.back());
        if (a > 2) cout << "\n";
    }
}
