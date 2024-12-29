#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

pi init(vector<pi> &a, vector<pi> &st, int n, int s, int e) {
    if (s == e) return st[n] = a[s];
    return st[n] = min(init(a, st, n * 2, s, (s + e) / 2), init(a, st, n * 2 + 1, (s + e) / 2 + 1, e));
}

pi find(vector<pi> &tree, int n, int s, int e, int l, int r) {
    if (e < l || r < s) return {1e9, 1e9};
    if (l <= s && e <= r) return tree[n];
    return min(find(tree, n * 2, s, (s + e) / 2, l, r), find(tree, n * 2 + 1, (s + e) / 2 + 1, e, l, r));
}


void update(vector<pi> &tree, int n, int s, int e, int idx, int num) {
    if (idx < s || e < idx) return;
    if (s == e) {
        tree[n].first = num;
        return;
    }
    tree[n].first = min(tree[n].first, num);
    if (s != e) {
        update(tree, n * 2, s, (s + e) / 2, idx, num);
        update(tree, n * 2 + 1, (s + e) / 2 + 1, e, idx, num);
        tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n;
    vector<pair<int, int>> arr(n + 1), tree((n + 1) * 4);
    for (int i = 1; i <= n; i++) cin >> arr[i].first, arr[i].second = i;
    init(arr, tree, 1, 1, n);
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) update(tree, 1, 1, n, b, c);
        else cout << find(tree, 1, 1, n, b, c).second << "\n";
    }
}
