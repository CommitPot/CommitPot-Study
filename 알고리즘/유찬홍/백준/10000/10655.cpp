#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int n, a, b, sx, sy, sum = 0, w = 0;
    vector<pair<int, int>> l;
    cin >> n >> sx >> sy;
    l.emplace_back(sx, sy);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        l.emplace_back(a, b);
        sum += dist({sx, sy}, {a, b});
        sx = a;
        sy = b;
    }
    for (int i = 1; i < n - 1; i++) {
        a = dist(l[i - 1], l[i]) + dist(l[i], l[i + 1]);
        b = dist(l[i - 1], l[i + 1]);
        w = max(w, a - b);
    }
    cout << sum - w;
}
