#include <iostream>

using namespace std;

int main() {
    int n, m;
    string a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        for (auto j: c) {
            b += j;
            b += j;
        }
    }
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        a += c;
    }
    cout << (a == b ? "Eyfa" : "Not Eyfa");
}
