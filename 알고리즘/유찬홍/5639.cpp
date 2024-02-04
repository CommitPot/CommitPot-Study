#include <iostream>

using namespace std;

struct Node {
    int n;
    Node *l, *r;
};

Node *push(Node *n, int x) {
    if (n == nullptr) {
        n = new Node();
        n->n = x;
        n->l = n->r = nullptr;
    } else {
        if (n->n < x) n->r = push(n->r, x);
        else n->l = push(n->l, x);
    }
    return n;
}

void postorder(Node *n) {
    if (n == nullptr) return;
    postorder(n->l);
    postorder(n->r);
    cout << n->n << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    Node *root = nullptr;
    while (cin >> n) root = push(root, n);
    postorder(root);
}
