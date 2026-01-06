#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    while (n--) {
        int c = 0;
        cin >> s;
        while (s != "6174") {
            sort(s.begin(), s.end(), greater<>());
            string r = s;
            reverse(r.begin(), r.end());
            s = to_string((stoi(s) < 1000 ? stoi(s) * 10 : stoi(s)) - stoi(r));
            c++;
        }
        cout << c << "\n";
    }
}
