#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, r, u, v, s = 2, vis[100001] = {0};
    vector<int> arr[100001];
    queue<int> q;
    cin >> n >> m >> r;
    while (m--) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(arr[i].begin(), arr[i].end());
    }
    q.push(r);
    vis[r] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i: arr[x]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = s++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << "\n";
    }
}
