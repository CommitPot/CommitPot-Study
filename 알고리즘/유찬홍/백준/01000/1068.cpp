#include <iostream>
#include <vector>

using namespace std;
int cnt = 0, a, c = 0;

void dfs(int *vis, const vector<int> *tree, int x) {
    if (tree[x].empty() || (tree[x].front() == a && tree[x].size() == 1)) {
        cnt++;
        return;
    }
    for (auto i: tree[x]) {
        if (!vis[i] && i != a) {
            c++;
            vis[i] = 1;
            dfs(vis, tree, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> tree[51];
    int n, r, vis[51] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == -1) r = i;
        else tree[a].emplace_back(i);
    }
    cin >> a;
    if (a == r) {
        cout << 0;
        return 0;
    }
    dfs(vis, tree, r);
    cout << (!c ? 1 : cnt);
}
