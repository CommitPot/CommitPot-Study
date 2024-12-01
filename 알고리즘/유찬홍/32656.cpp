#include <cstdio>
#include <vector>

using namespace std;
int n, j, k, x = 1;
vector<int> l[200001];

int f(int v, int p) {
    if (v == n || v == j) return x = 0;
    if (l[v].size() == 1 && l[v][0] == p) return 1;
    int c = 0;
    for (int i: l[v]) {
        if (i == p) continue;
        int z = f(i, v);
        if (v == k) {
            if (x) c += z;
            x = 1;
        } else c += z;
    }
    return v == k || c ? ++c : 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &j, &k);
        l[j].emplace_back(k);
        l[k].emplace_back(j);
    }
    scanf("%d %d %d", &n, &j, &k);
    if (j == k) j = 0;
    if (n == k) n = 0;
    printf("%d", f(k, 0));
}
