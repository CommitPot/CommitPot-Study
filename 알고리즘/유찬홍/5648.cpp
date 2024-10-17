#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<long long> a;
    string b;
    char s[13];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        b = s;
        reverse(b.begin(), b.end());
        a.emplace_back(stoll(b));
    }
    sort(a.begin(), a.end());
    for (auto i: a) printf("%lld\n", i);
}
