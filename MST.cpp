#include <bits/stdc++.h>

#define int long long

using namespace std;

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

bool comp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> g[i][0] >> g[i][1] >> g[i][2];
        g[i][0]--;
        g[i][1]--;
    }
    sort(g.begin(), g.end(), comp);
    make_dsu(n);
    int c = 0, s = 0;
    for (int i = 0; i < m; i++) {
        if (c >= n - 1)
            break;
        int a = dsu_get(g[i][0]), b = dsu_get(g[i][1]);
        if (a == b)
            continue;
        c++;
        s += g[i][2];
        dsu_union(a, b);
    }
    cout << s << "\n";
}