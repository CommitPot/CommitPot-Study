#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    unordered_set<string> u;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size() - i; j++) {
            u.insert(s.substr(j, i + 1));
        }
    }
    cout << u.size();
}
