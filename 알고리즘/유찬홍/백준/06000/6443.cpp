#include <iostream>
#include <algorithm>

using namespace std;

string s;
int vis[21];

void func(const string &str, int len) {
    if (str.length() == s.length()) {
        cout << str << "\n";
        return;
    }
    int visit[26] = {0};
    for (int i = 0; i < len; i++) {
        if (!vis[i] && !visit[s[i] - 97]) {
            vis[i] = 1;
            visit[s[i] - 97]++;
            func(str + s[i], len);
            vis[i] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        sort(s.begin(), s.end());
        func("", s.length());
    }
}
