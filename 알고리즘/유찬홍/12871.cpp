#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string a, b, c, d;
    cin >> a >> b;
    for (int i = 0; i < b.size(); i++) c += a;
    for (int i = 0; i < a.size(); i++) d += b;
    cout << (c == d);
}
