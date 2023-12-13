#include <iostream>
#include <deque>

using namespace std;
int vis[10000] = {0};
deque<pair<int, string>> q;

void push(int x, const string &s) {
    if (!vis[x]) {
        q.emplace_back(x, s);
        vis[x] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        q.emplace_back(a, "");
        vis[a] = 1;
        while (!q.empty()) {
            auto [x, s] = q.front();
            if (x == b) {
                cout << s << "\n";
                break;
            }
            q.pop_front();
            a = x * 2 % 10000;
            push(a, s + 'D');
            a = !x ? 9999 : x - 1;
            push(a, s + 'S');
            a = x % 1000 * 10 + x / 1000;
            push(a, s + 'L');
            a = x % 10 * 1000 + x / 10;
            push(a, s + 'R');
        }
        q.clear();
        for (int &i: vis) i = 0;
    }
}
