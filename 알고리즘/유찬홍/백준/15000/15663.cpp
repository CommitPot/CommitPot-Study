#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v, s;
int vis[10], n, m;

void func() {
    if (s.size() == m) {
        for (int i: s) cout << i << " ";
        cout << "\n";
        return;
    }
    int visit[10001] = {0};
    for (int i = 0; i < n; i++) {
        if (!vis[i] && !visit[v[i]]) {
            vis[i] = 1;
            s.emplace_back(v[i]);
            visit[v[i]]++;
            func();
            s.pop_back();
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v.emplace_back();
    sort(v.begin(), v.end());
    func();
}
