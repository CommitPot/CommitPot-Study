#include <iostream>

using namespace std;

pair<int, int> a[500001];
int r[500001];

void g(int s, int m, int e) {
    int i = s, j = m + 1, k = 0;
    pair<int, int> t[e - s + 1];
    while (i <= m && j <= e) {
        if (a[i] < a[j]) t[k++] = a[i++];
        else r[a[j].second] += m - i + 1, t[k++] = a[j++];
    }
    while (i <= m) t[k++] = a[i++];
    while (j <= e) t[k++] = a[j++];
    for (i = s, k = 0; i <= e; i++, k++) a[i] = t[k];
}

void f(int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        f(s, m);
        f(m + 1, e);
        g(s, m, e);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string rs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    f(0, n - 1);
    for (int i = 0; i < n; i++) rs += to_string(r[i] + 1) + "\n";
    cout << rs;
}
