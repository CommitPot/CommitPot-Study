#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<int, int> map;
    vector<int> arr;
    int a, b, c, a1[500000];
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> a1[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> c;
        map[c] = 1;
    }
    for (int i = 0; i < a; i++) {
        if (map[a1[i]] != 1) {
            arr.push_back(a1[i]);
        }
    }
    std::sort(arr.begin(), arr.end());
    cout << arr.size() << "\n";
    for (int i: arr) {
        cout << i << " ";
    }
}
