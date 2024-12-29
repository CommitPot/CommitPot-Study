#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, sum = 0, r = 1, t = 1, r1;
    cin >> n;
    while (r <= n) r *= 10, t++;
    r /= 10;
    r1 = --t;
    while (r) {
        sum += (n - r) * t;
        n = r;
        r /= 10;
        t--;
    }
    printf("%d", sum + r1);
}
