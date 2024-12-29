#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k;
vector<int> l[51];

int f(int v) {
    sort(l[v].begin(), l[v].end(), [](int a, int b) {
        return f(a) > f(b);
    });
    int x = 0, r = 0;
    for (auto i: l[v]) r = max(r, f(i) + x++);
    return r + 1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1, a; i < n; i++) {
        cin >> a;
        l[a].emplace_back(i);
    }
    cout << f(0) - 1;
}
