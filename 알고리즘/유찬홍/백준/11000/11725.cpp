#include <iostream>
#include <vector>

using namespace std;

void dfs(int *vis, vector<int> *arr, int x) {
    for (auto i: arr[x]) {
        if (!vis[i]) {
            vis[i] = x;
            dfs(vis, arr, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr[100001];
    int n, a, b, vis[100001] = {0};
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        arr[a].emplace_back(b);
        arr[b].emplace_back(a);
    }
    dfs(vis, arr, 1);
    for (int i = 2; i <= n; i++) {
        cout << vis[i] << "\n";
    }
}
