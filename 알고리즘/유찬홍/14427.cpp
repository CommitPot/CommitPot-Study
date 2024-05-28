#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

pi init(vector<pi> &a, vector<pi> &st, int n, int s, int e) {
    if (s == e) return st[n] = a[s];
    return st[n] = min(init(a, st, n * 2, s, (s + e) / 2), init(a, st, n * 2 + 1, (s + e) / 2 + 1, e));
}

void update(vector<pi> &tree, int s, int e, int n, int idx, int num) {
    if (idx < s || e < idx) return;
    if (s == e) {
        tree[n].first = num;
        return;
    }
    tree[n].first = min(tree[n].first, num);
    if (s != e) {
        update(tree, s, (s + e) / 2, n * 2, idx, num);
        update(tree, (s + e) / 2 + 1, e, n * 2 + 1, idx, num);
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
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            cin >> b >> c;
            update(tree, 1, n, 1, b, c);
        } else {
            cout << tree[1].second << "\n";
        }
    }
}
