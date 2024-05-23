#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, arr[101];
    cin >> n;
    for (int &i: arr) i = -1;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        arr[a] = b + 1;
    }
    cin >> m;
    for (int i = 0, a; i < m; i++) {
        cin >> a;
        int c = a;
        string s;
        for (int j = 0, b; j < a; j++) {
            cin >> b;
            if (arr[b] >= 0) s += to_string(arr[b] - 1) + " ";
            else c--;
        }
        cout << (c != a ? "YOU DIED" : s) << "\n";
    }
}
