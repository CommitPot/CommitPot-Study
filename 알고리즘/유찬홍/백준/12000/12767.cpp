#include <iostream>
#include <unordered_set>

using namespace std;

typedef struct N {
    int v;
    N *l, *r;
} N;

string s;

N *k(N *r, int v) {
    if (r == nullptr) {
        r = new N;
        r->v = v;
        r->l = r->r = nullptr;
        return r;
    }
    if (r->v < v) {
        r->r = k(r->r, v);
    } else {
        r->l = k(r->l, v);
    }
    return r;
}

void f(N *r) {
    if (r->l != nullptr) {
        s += 'l';
        f(r->l);
    }
    if (r->r != nullptr) {
        s += 'r';
        f(r->r);
    }
    s += 'e';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, v;
    unordered_set<string> st;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        N *r = nullptr;
        for (int j = 0; j < m; j++) {
            cin >> v;
            r = k(r, v);
        }
        f(r);
        st.emplace(s);
        s = "";
    }
    cout << st.size();
}
