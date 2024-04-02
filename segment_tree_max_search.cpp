// [l, r)
const int INF = [MAX NUMBER];
vector<int> tree;

void build(int v, int l, int r, vector<int> &a) {
    if (l + 1 == r)
        tree[v] = a[l];
    else {
        int m = (l + r) / 2;
        build(2 * v + 1, l, m, a);
        build(2 * v + 2, m, r, a);
        tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

int get_max(int v, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return tree[v];
    else if (r <= ql || l >= qr)
        return -INF;
    else {
        int m = (l + r) / 2;
        return (max(get_max(2 * v + 1, l, m, ql, qr), get_max(2 * v + 2, m, r, ql, qr)));
    }
}

void update(int v, int l, int r, int i, int val) {
    if (l + 1 == r)
        tree[v] = val;
    else {
        int m = (l + r) / 2;
        if (i < m)
            update(2 * v + 1, l, m, i, val);
        else
            update(2 * v + 2, m, r, i, val);
        tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

signed main() {
    int n = [SIZE];
    vector<int> a(n);
    tree.resize(n * 4);
    build(0, 0, n, a);
}
