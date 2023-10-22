#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list[100001];
int cnt = 1, vis[100001];


void dfs(int x) {
    for (auto i: list[x]) {
        if (!vis[i]) {
            vis[i] = ++cnt;
            dfs(i);
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, r, a, b;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(list[i].begin(), list[i].end(), greater<>());
    vis[r] = 1;
    dfs(r);
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << "\n";
    }
}
