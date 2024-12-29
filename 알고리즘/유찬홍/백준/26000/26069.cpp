#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, cnt = 1;
    string a, b;
    vector<string> list;
    list.emplace_back("ChongChong");
    cin >> n;
    while (n--) {
        cin >> a >> b;
        int ac = 0, bc = 0;
        for (const string &str: list) {
            if (a == str) ac++;
            if (b == str) bc++;
        }
        if (ac != bc) {
            cnt++;
            if (!ac) list.emplace_back(a);
            else list.emplace_back(b);
        }
    }
    cout << cnt;
}
