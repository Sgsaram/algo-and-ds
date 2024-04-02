vector<int> p, cnt;

void make_dsu(int n) {
    p.resize(n);
    cnt.resize(n);
    for (int i = 0; i < n; i++)
        p[i] = i;
}

int dsu_get(int v) {
    if (p[v] == v)
        return v;
    return p[v] = dsu_get(p[v]);
}

void dsu_union(int a, int b) {
    a = dsu_get(a);
    b = dsu_get(b);
    if (a == b)
        return;
    if (cnt[a] < cnt[b])
        swap(a, b);
    p[b] = a;
    if (cnt[a] == cnt[b])
        cnt[a]++;
}

signed main() {
    int n = [SIZE];
    make_dsu(n);
}
