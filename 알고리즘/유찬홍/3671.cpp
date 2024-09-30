#include <iostream>
#include <unordered_set>

using namespace std;

int r, vis[7];
string a;
bool p[10000001];
unordered_set<int> set;

void f(const string &s) {
    if (s.size() >= a.size()) return;
    for (int i = 0; i < a.size(); i++) {
        if (!vis[i]) {
            vis[i] = 1;
            f(s + a[i]);
            int x = stoi(s + a[i]);
            r += !p[x] && set.find(x) == set.end();
            set.insert(x);
            vis[i] = 0;
        }
    }
}

int main() {
    for (int i = 2; i * i < 10000001; i++) {
        if (p[i]) continue;
        for (int j = i * 2; j < 10000001; j += i) p[j] = true;
    }
    p[0] = p[1] = true;
    int n;
    cin >> n;
    while (n--) {
        cin >> a;
        f("");
        cout << r << '\n';
        r = 0, set.clear();
    }
}
