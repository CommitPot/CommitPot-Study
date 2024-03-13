#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int s, p, d = 0, a[4], b[4] = {0};
    string str;
    cin >> s >> p >> str;
    for (int &i: a) cin >> i;
    for (int i = 0; i < p - 1; i++) {
        if (str[i] == 'A') b[0]++;
        else if (str[i] == 'C') b[1]++;
        else if (str[i] == 'G') b[2]++;
        else b[3]++;
    }
    for (int i = 0, j = p - 1; i <= s - p; i++, j++) {
        if (i) {
            if (str[i - 1] == 'A') b[0]--;
            else if (str[i - 1] == 'C') b[1]--;
            else if (str[i - 1] == 'G') b[2]--;
            else b[3]--;
        }
        if (str[j] == 'A') b[0]++;
        else if (str[j] == 'C') b[1]++;
        else if (str[j] == 'G') b[2]++;
        else b[3]++;
        bool c = false;
        for (int k = 0; k < 4; k++) {
            if (a[k] > b[k]) {
                c = true;
                break;
            }
        }
        if (!c) d++;
    }
    cout << d;
}
