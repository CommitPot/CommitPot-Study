#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, vis[50001] = {};
    vector<int> l[50001];
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        l[a].emplace_back(b);
        l[b].emplace_back(a);
    }
    vis[1] = 1;
    queue<int> q;
    q.emplace(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i: l[v]) {
            if (!vis[i]) {
                vis[i] = vis[v] + 1;
                q.emplace(i);
            }
        }
    }
    int a = 0, b = 0, c = 0;
    for (int i = 2; i <= n; i++) {
        if (a <= vis[i]) {
            if (a == vis[i]) c++;
            else {
                a = vis[i];
                b = i;
                c = 1;
            }
        }
    }
    cout << b << " " << a - 1 << " " << c;
}
