#include <bits/stdc++.h>

using namespace std;

class BST;
class Node {
    public:
        char val;
        int isWord;
        Node *ch[2];
        Node *parent;
        BST *middle;
        Node(char c, Node *p = nullptr): val(c), parent(p), middle(nullptr), ch{nullptr, nullptr} {}
};

class BST {
    public:
        Node *root;
        BST(): root(nullptr) {}
        void insert(string s);
        int find(string s);
        void rotate(Node *x);
        void splay(Node *x, Node *target);
};

int get(Node *x) {
    return x->parent->ch[1] == x;
}

void BST::rotate(Node *x) {
    Node *y = x->parent;
    Node *z = y->parent;
    int t = get(x);
    y->ch[t] = x->ch[t ^ 1];
    if (x->ch[t ^ 1]) x->ch[t ^ 1]->parent = y;
    x->ch[t ^ 1] = y;
    y->parent = x;
    if (z) z->ch[y == z->ch[1]] = x;
    x->parent = z;
}

void BST::splay(Node *x, Node *target) {
    for (Node *f; f = x->parent, f != target; this->rotate(x)) {
        if (f->parent != target) this->rotate((get(x) == get(f)) ? f : x);
    }
    if (target == NULL) root = x;
}

void BST::insert(string s) {
    if (!this->root) this->root = new Node(s[0]);
    Node *x = this->root;
    for (; ; ) {
        if (s[0] == x->val) {
            if (s.length() == 1) {
                x->isWord = 1;
                // rotate current node to root of the bst
                this->splay(x, nullptr);
                return;
            }
            if (!x->middle) x->middle = new BST();
            x->middle->insert(s.substr(1));
            return;
        }
        else {
            int t = s[0] > x->val;
            if (!x->ch[t]) {
                x->ch[t] = new Node(s[0], x);
            }
            x = x->ch[t];
        }
    }
}

int BST::find(string s) {
    Node *x = this->root;
    for (; ; ) {
        if (!x) return 0;
        if (s[0] == x->val) {
            if (s.length() == 1) {
                // rotate current node to root of the bst
                this->splay(x, nullptr);
                return x->isWord;
            }
            return x->middle->find(s.substr(1));
        }
        else {
            x = x->ch[s[0] > x->val];
        }
    }
}

int main() {
    BST *a = new BST();

    int n;
    cin >> n;
    for (; n--; ) {
        string o, s;
        cin >> o >> s;
        if (o[0] == 'I') a->insert(s);
        else if (o[0] == 'Q') cout << a->find(s) << endl;
    }

    return 0;
}