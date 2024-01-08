#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout.tie(nullptr), cin.tie(nullptr), ios::sync_with_stdio(false);

    vector<long long int> liquid;
    int n, s = 0, e;
    long long int answer[2] = {1000000000, 1000000000};

    cin >> n;
    e = n - 1;

    for (int i = 0; i < n; ++i) {
        int in;
        cin >> in;
        liquid.push_back(in);
    }
    sort(liquid.begin(), liquid.end());
    while (s < e) {
        if (liquid[s] + liquid[e] == 0) {
            cout << liquid[s] << " " << liquid[e];
            return 0;
        }
        if (abs(liquid[s] + liquid[e]) <= abs(answer[0] + answer[1])) {
            answer[0] = liquid[s];
            answer[1] = liquid[e];
        }
        if (liquid[s] + liquid[e] < 0) s++;
        else if (liquid[s] + liquid[e] > 0) e--;
    }
    cout << answer[0] << " " << answer[1];
}
