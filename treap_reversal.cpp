#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9,
INF = 1e11 + 7;

mt19937 rnd(179);

struct Node {
    int x, y, cnt, min_val;
    bool rev;
    Node *l, *r;
    Node(int x) : x(x) {
        y = rnd();
        cnt = 1;
        rev = false;
        min_val = x;
        l = r = nullptr;
    }
    ~Node() {
        delete l;
        delete r;
    }
};

int get_cnt(Node *v) {
    if (!v)
        return 0;
    return v->cnt;
}

int get_min_val(Node *v) {
    if (!v)
        return INF;
    return v->min_val;
}

void update(Node *v) {
    if (v) {
        v->cnt = get_cnt(v->l) + get_cnt(v->r) + 1;
        v->min_val = min(min(get_min_val(v->l), get_min_val(v->r)), v->x);
    }
}

void push(Node *v) {
    if (v && v->rev) {
        swap(v->l, v->r);
        v->rev = false;
        if (v->l)
            v->l->rev ^= 1;
        if (v->r)
            v->r->rev ^= 1;
    }
}

pair<Node*, Node*> split(Node *t, int k) {
    if (t == nullptr)
        return {nullptr, nullptr};
    push(t);
    int c = 0;
    if (t->l)
        c = t->l->cnt;
    if (c <= k) {
        auto [left, right] = split(t->r, k - c - 1);
        t->r = left;
        update(t);
        return {t, right};
    } else {
        auto [left, right] = split(t->l, k);
        t->l = right;
        update(t);
        return {left, t};
    }
}

Node* merge(Node *t1, Node *t2) {
    if (t1 == nullptr) {
        return t2;
    } else if (t2 == nullptr) {
        return t1;
    } else if (t1->y > t2->y) {
        push(t1);
        t1->r = merge(t1->r, t2);
        update(t1);
        return t1;
    } else {
        push(t2);
        t2->l = merge(t1, t2->l);
        update(t2);
        return t2;
    }
}

Node* add(Node *t, int k, int val) {
    Node *v = new Node(val);
    auto [left, right] = split(t, k);
    return merge(merge(left, v), right);
}

void reverse(Node *t, int l, int r) {
    auto [left, t_mid] = split(t, l - 1);
    auto [mid, right] = split(t_mid, r - l);
    mid->rev ^= 1;
    merge(left, merge(mid, right));
}

int get_min(Node *t, int l, int r) {
    auto [left, t_mid] = split(t, l - 1);
    auto [mid, right] = split(t_mid, r - l);
    int res = mid->min_val;
    merge(left, merge(mid, right));
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *t = nullptr;
    int n, m, a, req, l, r;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        t = add(t, i, a);
    }
    while (m--) {
        cin >> req >> l >> r;
        if (req == 1) {
            reverse(t, l - 1, r - 1);
        } else if (req == 2) {
            cout << get_min(t, l - 1, r - 1) << "\n";
        }
    }
}
