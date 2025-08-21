#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) q.emplace(i + 1);
    for (int i = 1; q.size() > 1; i++) {
        unsigned long long r = (long long) pow(i, 3) % (long long) q.size();
        r = r ? r : q.size();
        while (--r > 0) {
            q.emplace(q.front());
            q.pop();
        }
        q.pop();
    }
    cout << q.front();
}
