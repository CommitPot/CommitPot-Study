#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    unordered_set<string> s;
    string a;
    cin >> n;
    while (n--) {
        cin >> a;
        sort(a.begin(), a.end());
        s.insert(a);
    }
    cout << s.size();
}
