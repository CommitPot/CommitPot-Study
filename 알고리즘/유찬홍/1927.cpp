#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n, a;
    priority_queue<int> pq;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (!a) {
            if (pq.empty()) ::printf("0\n");
            else {
                ::printf("%d\n", -pq.top());
                pq.pop();
            }
        } else pq.push(-a);
    }
}
