#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool vis[11];
vector<long long int> l(1, 0);

void func(long long int v) {
    l.emplace_back(v);
    for (int i = 0; i <= 9; i++) {
        if (!vis[i] && v % 10 > i) {
            vis[i] = true;
            func(v * 10 + i);
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        func(i);
    }
    sort(l.begin(), l.end());
    cout << (n > 1023 ? -1 : l[n]);
}
