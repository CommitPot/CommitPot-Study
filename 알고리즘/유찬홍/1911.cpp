#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n, l;
    vector<pair<int, int>> m;
    scanf("%d %d", &n, &l);
    for (int i = 0, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        m.emplace_back(a, b);
    }
    sort(m.begin(), m.end());
    int s = 0, c = 0;
    for (auto [a, b]: m) {
        if (s < a) s = a;
        int z = ceil((double) (b - s) / l);
        c += z;
        s += z * l;
    }
    printf("%d", c);
}
