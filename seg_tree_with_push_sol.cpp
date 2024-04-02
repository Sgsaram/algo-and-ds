#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<vector<int>> tree;
vector<int> add;

void build(int v, int l, int r, const string &s) {
    if (l + 1 == r) {
        tree[v][s[l] - 'a'] = 1;
    } else {
        int m = (l + r) / 2;
        build(2 * v + 1, l, m, s);
        build(2 * v + 2, m, r, s);
        for (int i = 0; i < 26; i++)
            tree[v][i] = tree[2 * v + 1][i] + tree[2 * v + 2][i];
    }
}

vector<int> new_tree(26);

void push(int v, int &l, int &r) {
    new_tree.assign(26, 0);
    for (int i = 0; i < 26; i++)
        new_tree[(i + add[v]) % 26] = tree[v][i];
    for (int i = 0; i < 26; i++)
        tree[v][i] = new_tree[i];
    if (l + 1 < r) {
        add[2 * v + 1] += add[v];
        add[2 * v + 2] += add[v];
    }
    add[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int val) {
    push(v, l, r);
    if (r <= ql || qr <= l) {
        return;
    } else if (ql <= l && r <= qr) {
        new_tree.assign(26, 0);
        add[v] += val;
        push(v, l, r);
    } else {
        push(v, l, r);
        int m = (l + r) / 2;
        update(2 * v + 1, l, m, ql, qr, val);
        update(2 * v + 2, m, r, ql, qr, val);
        for (int i = 0; i < 26; i++)
            tree[v][i] = tree[2 * v + 1][i] + tree[2 * v + 2][i];
    }
}

vector<int> get(int v, int l, int r, int ql, int qr) {
    vector<int> res(26);
    push(v, l, r);
    if (r <= ql || qr <= l) {
        return res;
    } else if (ql <= l && r <= qr) {
        push(v, l, r);
        return tree[v];
    } else {
        int m = (l + r) / 2;
        push(v, l, r);
        vector<int> res1 = get(2 * v + 1, l, m, ql, qr),
        res2 = get(2 * v + 2, m, r, ql, qr);
        for (int i = 0; i < 26; i++)
            res[i] = res1[i] + res2[i];
        return res;
    }
}

vector<int> p_two(100005);
int calc(const vector<int> &a) {
    int res = 1, c = 0;
    for (int i = 0; i < 26; i++) {
        if (a[i] <= 0)
            continue;
        c++;
        res = (res * p_two[a[i] - 1]) % MOD;
    }
    res = ((res * (c + 1)) % MOD + MOD - 1) % MOD;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q, l, r, k, type;
    string s;
    cin >> n >> q >> s;
    p_two[0] = 1;
    for (int i = 1; i < 100005; i++)
        p_two[i] = (p_two[i - 1] * 2) % MOD;
    tree.resize(n * 4, vector<int>(26));
    add.resize(n * 4);
    build(0, 0, n, s);
    vector<int> res;
    while (q--) {
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> k;
            update(0, 0, n, l, r + 1, k);
        } else {
            res = get(0, 0, n, l, r + 1);
            cout << calc(res) << "\n";
        }
    }
}
