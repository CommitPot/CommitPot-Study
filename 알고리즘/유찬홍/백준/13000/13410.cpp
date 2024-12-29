#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, m, r = 0;
    string s;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        s = to_string(n * i);
        reverse(s.begin(), s.end());
        r = max(r, stoi(s));
    }
    cout << r;
}
