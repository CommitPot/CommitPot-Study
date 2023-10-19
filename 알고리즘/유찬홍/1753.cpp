#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> list[20001];
    priority_queue<pair<int, int>> queue;
    int n, m, s, a, b, c, dist[20001];
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n; i++) dist[i] = 1e9;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        list[a].emplace_back(b, c);
    }
    queue.emplace(0, s);
    dist[s] = 0;
    while (!queue.empty()) {
        int w = -queue.top().first;
        int cur = queue.top().second;
        queue.pop();
        for (auto &i: list[cur]) {
            int next = i.first;
            int nw = i.second;
            if (w + nw < dist[next]) {
                dist[next] = w + nw;
                queue.emplace(-dist[next], next);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 1e9) std::printf("INF\n");
        else std::printf("%d\n", dist[i]);
    }
}
