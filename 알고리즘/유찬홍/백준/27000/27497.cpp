#include <iostream>
#include <deque>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string s;
    deque<char> dq;
    stack<int> t;
    cin >> n;
    for (int i = 0, j; i < n; i++) {
        char d;
        cin >> j;
        if (j == 3 && !t.empty()) {
            if (t.top() == 1) dq.pop_front();
            else dq.pop_back();
            t.pop();
        }
        if (j < 3) {
            cin >> d;
            if (j == 1) t.push(0), dq.push_back(d);
            else t.push(1), dq.push_front(d);
        }
    }
    if (dq.empty()) cout << "0";
    else for (char i: dq) s += i;
    cout << s;
}
