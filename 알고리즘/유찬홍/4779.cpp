#include <iostream>
#include <cmath>

using namespace std;

string func(int n, string s) {
    if (n == 1) return "-";
    int n1 = n / 3;
    string s1, s2, s3;
    for (int i = 0; i < n1; i++) {
        s1 += '-';
        s3 += '-';
        s2 += ' ';
    }
    return func(n1, s1) + s2 + func(n1, s3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n)
        cout << func(pow(3, n), "") << "\n";
}
