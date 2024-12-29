#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> l[101];
int id, r, w[101], vis[101];
bool fin[101];
stack<int> s;

int f(int v) {
    int p = vis[v] = ++id;
    s.push(v);
    for (int i: l[v]) {
        if (!vis[i]) p = min(p, f(i));
        else if (!fin[i]) p = min(p, vis[i]);
    }

    if (p == vis[v]) {
        int a = 1e9;
        while (true) {
            int x = s.top();
            s.pop();
            fin[x] = true;
            if (a > w[x]) a = w[x];
            if (x == v) break;
        }
        r += a;
    }
    return p;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == '1') l[i].emplace_back(j + 1);
        }
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) f(i);
    cout << r;
}
