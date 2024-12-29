#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<int> pq;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (pq.size() < n) pq.push(-a);
            else {
                pq.push(-a);
                pq.pop();
            }
        }
    }
    cout << -pq.top();
}
