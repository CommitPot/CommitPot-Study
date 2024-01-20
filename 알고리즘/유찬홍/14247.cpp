#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct E {
    int a, b;
} E;

bool comp(E a, E b) {
    return a.b < b.b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    long long int sum = 0;
    cin >> n;
    vector<E> arr(n);
    for (E &i: arr) cin >> i.a;
    for (E &i: arr) cin >> i.b;
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < n; i++) sum += arr[i].a + arr[i].b * i;
    cout << sum;
}
