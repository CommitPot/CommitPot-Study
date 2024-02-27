#include <iostream>

using namespace std;

int t[100001][3], cnt;
bool vis[100001];

//다 돌고 루트로 올라감
void func(int v) {
    if (t[v][0] != -1 && !vis[t[v][0]]) cnt++, func(t[v][0]);
    if (t[v][1] != -1 && !vis[t[v][1]]) cnt++, func(t[v][1]);
    vis[v] = true;
    if (!vis[t[v][2]]) cnt++, func(t[v][2]);
}

//트리의 오른쪽 길이 재기
int r(int v, int c) {
    if (t[v][1] == -1) return c;
    return r(t[v][1], c + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        t[a][0] = b;
        t[a][1] = c;
        if (b != -1) t[b][2] = a;
        if (c != -1) t[c][2] = a;
    }
    vis[0] = true;
    func(1);
    //루트부터 루트까지의 순회 길이를 잰 후 오른쪽을 빼주면 유사 중위 순회가 된다.
    cout << cnt - r(1, 0);
}
