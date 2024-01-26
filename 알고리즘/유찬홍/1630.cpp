#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(1000001, 0), q, r;
    long long int a = 1;
    for (int i = 2; i <= 1000; i++) {
        if (!p[i]) {
            for (int j = i * 2; j <= 1000000; j += i) {
                p[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++) if (!p[i]) q.emplace_back(i);
    for (int i: q) {
        long long int b = i;
        while (b * i <= n) b *= i;
        a = a * b % 987654321;
    }
    cout << a;
}
