#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a;
    cin >> n;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (!s.empty() && s.top().first <= a) s.pop();
        cout << (s.empty() ? -1 : s.top().second) + 1 << " ";
        s.emplace(a, i);
    }
}
