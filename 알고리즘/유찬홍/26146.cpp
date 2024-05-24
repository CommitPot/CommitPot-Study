#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int id, c, vis[200001];
bool fin[200001];
vector<int> l[200001];
stack<int> s;

int f(int v) {
    int p = vis[v] = ++id;
    s.push(v);
    for (int i: l[v]) {
        if (!vis[i]) p = min(p, f(i));
        else if (!fin[i]) p = min(p, vis[i]);
    }

    if (p == vis[v]) {
        while (true) {
            int t = s.top();
            s.pop();
            fin[t] = true;
            if (t == v) break;
        }
        c++;
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        l[a].emplace_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) f(i);
    }
    cout << (c == 1 ? "Yes" : "No");
}
