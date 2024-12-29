#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> s;
int l[11], n, k;
bool vis[11];

void bt(int j, const string &a) {
    if (j == k) {
        if (s.find(a) == s.end()) {
            s.emplace(a);
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            bt(j + 1, a + to_string(l[i]));
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> l[i];
    bt(0, "");
    cout << s.size();
}
