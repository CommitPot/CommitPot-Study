#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a, b, r[105], v[10] = {9, 4, 8, 7, 2, 1, 6, 5, 0, 3};
    scanf("%d %d", &a, &b);
    for (int i = 0; i <= b - a; i++) r[i] = b - i;
    sort(r, r + b - a + 1, [&](int p, int q) {
        function l = [&](int w) {
            return w < 10 ? v[w] * 10 : v[w / 10] * 10 + v[w % 10];
        };
        return l(p) == l(q) ? p < q : l(p) < l(q);
    });
    for (int i = 0; i <= b - a; i++) printf("%d %s", r[i], i % 10 == 9 ? "\n" : "");
}
