#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, string> u;
    unordered_map<string, vector<string>> l;
    int n, m, c;
    char t[101];
    string s;
    scanf("%d %d", &n, &m);
    while (n--) {
        scanf("%s %d", t, &c);
        s = t;
        while (c--) {
            scanf("%s", t);
            u[t] = s;
            l[s].emplace_back(t);
        }
    }
    while (m--) {
        scanf("%s %d", t, &c);
        if (c) printf("%s\n", u[t].c_str());
        else {
            sort(l[t].begin(), l[t].end());
            for (const auto &i: l[t]) {
                printf("%s\n", i.c_str());
            }
        }
    }
}
