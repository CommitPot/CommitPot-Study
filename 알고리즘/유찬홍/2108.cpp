#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, sum = 0;
    cin >> n;
    vector<int> l;
    int nm[8001] = {};
    for (int i = 0; i < n; i++) {
        cin >> l.emplace_back();
        nm[(l[i] <= 0 ? l[i] * -1 : l[i] + 4000)]++;
        sum += l[i];
    }
    sort(l.begin(), l.end());
    int r = 0;
    vector<int> s;
    for (int i = 0; i < 8001; i++) {
        if (r <= nm[i]) {
            if (r < nm[i]) {
                s.clear();
                r = nm[i];
            }
            s.emplace_back((i > 4000 ? i - 4000 : i * -1));
        }
    }
    sort(s.begin(), s.end());
    int avg = round((double) sum / n);
    cout << (avg == -0 ? 0 : avg) << "\n" << l[n / 2] << "\n" << (s.size() == 1 ? s[0] : s[1]) << "\n"
         << l.back() - l.front();
}
