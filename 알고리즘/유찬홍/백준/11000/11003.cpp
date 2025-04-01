#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    deque<pair<int, int>> q;
    int n, m;
    string r;
    cin >> n >> m;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        while (!q.empty() && q.back().first > a) q.pop_back();
        q.push_back({a, i});
        while(q.front().second <= i - m) q.pop_front();
        r += to_string(q.front().first) + " ";
    }
    cout << r;
}
