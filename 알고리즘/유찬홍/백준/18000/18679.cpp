#include <map>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    map<string, string> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        m[a] = c;
    }
    cin >> n;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        string a, r;
        for (int j = 0; j < t; j++) {
            cin >> a;
            r += m[a] + " ";
        }
        cout << r << "\n";
    }
}
