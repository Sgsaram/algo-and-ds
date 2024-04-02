#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<vector<int>> g;
vector<int> t;
vector<bool> used;

void top_sort(int v) {
    used[v] = true;
    for (int u : g[v])
        if (!used[u])
            top_sort(u);
    t.push_back(v);
}

int mex(const set<int> &a) {
    int res = 0;
    while (a.count(res))
        res++;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    vector<int> fgr(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; i++)
        if (!used[i])
            top_sort(i);
    for (int i : t) {
        set<int> a;
        for (int u : g[i])
            a.insert(fgr[u]);
        fgr[i] = mex(a);
    }
    for (int i : fgr)
        cout << i << "\n";
}
