#include <iostream>
#include <vector>

using namespace std;

vector<int> p;

int f(int v) { return p[v] = p[v] == v ? v : f(p[v]); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b;
    cin >> n;
    p.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 2; i < n; i++) {
        cin >> a >> b;
        a = f(a);
        b = f(b);
        if (a == b) continue;
        p[max(a, b)] = min(a, b);
    }
    for (int i = 1; i <= n; i++) f(i);
    a = 1e9, b = -1;
    for (int i = 1; i <= n; i++) {
        if (a > p[i]) a = p[i];
        if (b < p[i]) b = p[i];
    }
    cout << a << " " << b;
}
