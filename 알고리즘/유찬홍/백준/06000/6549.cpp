#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;

pi init(vector<int> &a, vector<pi> &st, int s, int e, int n = 1) {
    if (s == e) return st[n] = pi{a[s], s};
    int mid = (s + e) / 2;
    return st[n] = min(init(a, st, s, mid, n * 2), init(a, st, mid + 1, e, n * 2 + 1));
}

pi findMinIndex(vector<pi> &tree, int s, int e, int l, int r, int n = 1) {
    if (e < l || r < s) return {1e9 + 1, 1e9 + 1};
    if (l <= s && e <= r) return tree[n];
    int mid = (s + e) / 2;
    return min(findMinIndex(tree, s, mid, l, r, n * 2), findMinIndex(tree, mid + 1, e, l, r, n * 2 + 1));
}

ll find(vector<int> &a, vector<pi> &tree, int l, int r, int n) {
    if (l == r) return a[l];
    pi x = findMinIndex(tree, 1, n, l, r);
    ll rs = (r - l + 1) * x.first;
    if (l < x.second) rs = max(rs, find(a, tree, l, x.second - 1, n));
    if (r > x.second) rs = max(rs, find(a, tree, x.second + 1, r, n));
    return rs;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    while (cin >> n, n) {
        vector<int> arr(n + 1);
        vector<pi> tree(1 << (int) (ceil(log2(n)) + 1));
        for (int i = 1; i <= n; i++) cin >> arr[i];
        init(arr, tree, 1, n);
        cout << find(arr, tree, 1, n, n) << "\n";
    }
}
