#include <iostream>
#include <vector>

using namespace std;
int cnt;

void dfs(int x, vector<int> list[], bool *vis) {
    cnt++;
    for (int i: list[x]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i, list, vis);
        }
    }
}

int main() {
    int n, m, a, b;
    bool vis[100001];
    vector<int> arr[100001];
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[b].push_back(a);
    }
    cin >> a;
    dfs(a, arr, vis);
    cout << cnt - 1;
}
