#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long int a, b, c, d;
    string e;
    unordered_map<string, long long int> m, m1;
    cin >> a >> b >> c;
    while (a--) {
        cin >> e >> d;
        m[e] = d;
    }
    while (b--) {
        cin >> e >> d;
        m1[e] = d;
    }
    while (c--) cin >> e;
    cin >> a;
    b = c = d = 0;
    while (a--) {
        cin >> e;
        if (m.find(e) == m.end()) {
            if (m1.find(e) == m.end()) d++;
            else c += m1[e];
        } else b += m[e];
    }
    cout << ("%s", ((d > 1) || (b < 20000 && c) || (b + c < 50000 && d)) ? "No" : "Okay");
}
