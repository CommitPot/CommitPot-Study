#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, in;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in;
        arr.push_back(in);
    }
    sort(arr.begin(), arr.end(), greater<>());
    int l = arr[0];
    int sum = arr[0] + arr[1];
    for (int i = 2; i < n; i++) {
        sum += l + arr[i];
    }
    cout << sum;
}
