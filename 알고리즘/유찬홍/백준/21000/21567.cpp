#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long int a, b, c;
    int d[10] = {0};
    cin >> a >> b >> c;
    a *= b * c;
    auto s = to_string(a);
    for (char i: s) d[i - 48]++;
    for (int i: d) {
        cout << i << "\n";
    }
}
