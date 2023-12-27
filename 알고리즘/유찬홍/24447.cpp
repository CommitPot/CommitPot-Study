#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, r, a, b, s = 2, vis[100001] = {0};
    long long int sum = 0;
    queue<int> q;
    vector<int> map[100001];
    cin >> n >> m >> r;
    while (m--) {
        cin >> a >> b;
        map[a].emplace_back(b);
        map[b].emplace_back(a);
    }
    vis[r] = 1;
    q.emplace(r);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        sort(map[v].begin(), map[v].end());
        for (int i: map[v]) {
            if (!vis[i]) {
                vis[i] = vis[v] + 1;
                sum += (long long int) s++ * vis[v];
                q.emplace(i);
            }
        }
    }
    cout << sum;
}
