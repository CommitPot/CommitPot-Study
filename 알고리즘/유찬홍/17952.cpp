#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    stack<pair<int, int>> s;
    int n, a, b, rs = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        if (!a) {
            if (!s.empty()) {
                if (--s.top().second <= 0) {
                    rs += s.top().first;
                    s.pop();
                }
            }
            continue;
        }
        cin >> a >> b;
        if (--b <= 0) rs += a;
        else s.emplace(a, b);
    }
    cout << rs;
}
