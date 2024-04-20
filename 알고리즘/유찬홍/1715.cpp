#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, cnt = 0;
    priority_queue<int> q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        q.emplace(-a);
    }
    while (q.size() > 1) {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        q.emplace(x + y);
        cnt -= x + y;
    }
    cout << cnt;
}
