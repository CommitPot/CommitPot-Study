#include <iostream>

using namespace std;
string s;
int c;
char v[11];
bool vis[11];

void f(int l) {
    if (l == s.size()) {
        c++;
        return;
    }
    bool al[26];
    for (auto &i: al) i = false;
    for (int i = 0; i < s.length(); i++) {
        if (!vis[i] && !al[s[i] - 97] && v[l - 1] != s[i]) {
            v[l++] = s[i];
            vis[i] = true;
            al[s[i] - 97] = true;
            f(l--);
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> s;
    f(0);
    cout << c;
}
