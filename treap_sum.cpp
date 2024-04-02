#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9;

mt19937 rnd(179);

struct Node {
    int x, y, s;
    Node *l, *r;
    Node(int x) : x(x) {
        y = rnd();
        s = x;
        l = r = nullptr;
    }
};

int sum_v(Node *v) {
    return v == nullptr ? 0 : v->s;
}

void update(Node *v) {
    if (v == nullptr)
        return;
    v->s = sum_v(v->l) + sum_v(v->r) + v->x;
}

pair<Node*, Node*> split(Node *t, int k) {
    if (t == nullptr) {
        return {nullptr, nullptr};
    } else if (t->x <= k) {
        auto [left, right] = split(t->r, k);
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
        t1->r = merge(t1->r, t2);
        update(t1);
        return t1;
    } else {
        t2->l = merge(t1, t2->l);
        update(t2);
        return t2;
    }
}

bool count(Node *t, int k) {
    if (t == nullptr) {
        return false;
    } else if (t->x == k) {
        return true;
    } else if (t->x > k) {
        return count(t->l, k);
    } else {
        return count(t->r, k);
    }
}

Node* add(Node *t, int k) {
    if (count(t, k))
        return t;
    Node *v = new Node(k);
    auto [left, right] = split(t, k);
    return merge(merge(left, v), right);
}

int get_sum(Node *t, int l, int r) {
    auto [left, t_mid] = split(t, l - 1);
    auto [mid, right] = split(t_mid, r);
    int res = sum_v(mid);
    merge(left, merge(mid, right));
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *t = nullptr;
    int n, last_res = 0, x, l, r;
    char req;
    cin >> n;
    while (n--) {
        cin >> req;
        if (req == '+') {
            cin >> x;
            t = add(t, (x + last_res) % MOD);
            last_res = 0;
        } else if (req == '?') {
            cin >> l >> r;
            last_res = get_sum(t, l, r);
            cout << last_res << "\n";
        }
    }
}
