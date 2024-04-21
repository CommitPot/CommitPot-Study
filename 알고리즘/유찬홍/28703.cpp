#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    long long int r = -1, r1, a, rs;
    priority_queue<long long int> q;
    cin >> n;
    while (n--) {
        cin >> a;
        r = max(a, r);
        q.emplace(-a);
    }
    rs = r + q.top();
    r1 = r;
    while (-q.top() <= r) {
        auto v = -q.top();
        q.pop();
        rs = min(rs, r1 - v);
        r1 = max(r1, v * 2);
        q.emplace(-(v * 2));
    }
    cout << rs;
}
