#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

string s, arr;
int sw = 0, n;
deque<int> q;
vector<int> l;

bool func() {
    for (char i: s) {
        if (i == 'R') sw = !sw;
        else {
            if (q.empty()) return false;
            if (sw) q.pop_back();
            else q.pop_front();
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, rs = 0;
    cin >> t;
    while (t--) {
        cin >> s >> n >> arr;
        for (char i: arr) {
            if ((i == ',' || i == ']') && rs) {
                q.emplace_back(rs);
                rs = 0;
            }
            if (i > 47 && i < 59) rs = rs * 10 + (i - 48);
        }
        if (!func()) cout << "error\n";
        else {
            cout << "[";
            for (int i: q) l.emplace_back(i);
            if (sw) reverse(l.begin(), l.end());
            for (int i = 0; i < l.size(); i++) {
                cout << l[i];
                if (i != l.size() - 1) cout << ",";
            }
            cout << "]\n";
        }
        sw = rs = 0;
        q.clear();
        l.clear();
    }
}
