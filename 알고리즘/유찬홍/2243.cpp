#include <iostream>
#include <algorithm>

using namespace std;

void u(vector<int> &tree, int s, int e, int idx, int r, int n = 1) {
    if (idx < s || idx > e) return;
    tree[n] += r;
    if (s != e) {
        int m = (s + e) / 2;
        u(tree, s, m, idx, r, n * 2);
        u(tree, m + 1, e, idx, r, n * 2 + 1);
    }
}

int f(vector<int> &tree, int k, int t, int n = 1) {
    tree[n]--;
    if (n >= t) return n - t;
    if (tree[n * 2] >= k) return f(tree, k, t, n * 2);
    return f(tree, k - tree[n * 2], t, n * 2 + 1);
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> tree(1 << 21);
    while (n--) {
        int a, b, c;
        cin >> a >> b;
        if (a == 1) cout << f(tree, b, 1 << 20) + 1 << "\n";
        else {
            cin >> c;
            u(tree, 1, 1 << 20, b, c);
        }
    }
}
