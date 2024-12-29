#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

bool vis[100001];
vector<int> arr[100001];
vector<int> l;

void dfs(int v) {
    if (arr[v].empty()) l.emplace_back(v);
    for (int i: arr[v]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, a, b;
    unordered_set<int> s;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        arr[a].emplace_back(b);
    }
    cin >> m;
    while (m--) {
        cin >> a;
        vis[a] = true;
        s.emplace(a);
    }
    if (!vis[1]) dfs(1);
    for (int i: l) {
        if (s.find(i) == s.end()) {
            cout << "yes";
            return 0;
        }
    }
    cout << "Yes";
}
