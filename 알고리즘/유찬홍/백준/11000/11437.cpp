#include <vector>
#include <iostream>

using namespace std;

vector<int> node[50001];
bool vis[50001];
int p[50001], d[50001];

void dfs(int x, int depth) {
    vis[x] = true;
    d[x] = depth;
    for (auto i: node[x]) {
        if (vis[i]) continue;
        p[i] = x;
        dfs(i, depth + 1);
    }
}

int main() {
    int n, m, a, b;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    cin >> m;
    dfs(1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        while (d[a] != d[b]) {
            if (d[a] > d[b]) a = p[a];
            else b = p[b];
        }
        while (a != b) {
            a = p[a];
            b = p[b];
        }
        cout << a << "\n";
    }
}
