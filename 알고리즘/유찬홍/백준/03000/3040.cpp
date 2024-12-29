#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = 0, a;
    vector<int> arr;
    for (int i = 0; i < 9; i++) {
        cin >> a;
        arr.push_back(a);
        sum += a;
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        cout << arr[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }
}
