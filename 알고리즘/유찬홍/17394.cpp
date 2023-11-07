#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n, a, b, prime[100001] = {0};
    prime[0] = prime[1] = 1;
    for (int i = 2; i < 318; i++) {
        if (!prime[i]) {
            for (int j = i * 2; j < 100001; j += i) {
                prime[j] = 1;
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        int vis[1000001] = {0}, s = 0;
        queue<int> q;
        q.push(n);
        vis[n] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (a <= x && x <= b && !prime[x]) {
                cout << vis[x] - 1 << "\n";
                s = 1;
                break;
            }
            if (!vis[x / 2]) {
                q.push(x / 2);
                vis[x / 2] = vis[x] + 1;
            }
            if (!vis[x / 3]) {
                q.push(x / 3);
                vis[x / 3] = vis[x] + 1;
            }
            if (x + 1 < 1000001 && !vis[x + 1]) {
                q.push(x + 1);
                vis[x + 1] = vis[x] + 1;
            }
            if (x >= 1 && !vis[x - 1]) {
                q.push(x - 1);
                vis[x - 1] = vis[x] + 1;
            }
        }
        if (!s) cout << "-1" << "\n";
    }
}
