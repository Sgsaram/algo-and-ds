#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<vector<int>> g;
vector<bool> used, lp, rp;
vector<int> mt, nt;

void dfs(int v) {
    used[v] = true;
    lp[v] = true;
    for (int u : g[v]) {
        rp[u] = true;
        if (used[mt[u]])
            continue;
        dfs(mt[u]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c, a, res = 0;
    cin >> n >> m;
    used.resize(n);
    g.resize(n);
    nt.resize(n, -1);
    mt.resize(m, -1);
    lp.resize(n);
    rp.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> c;
        while (c--) {
            cin >> a;
            g[i].push_back(a - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0)
            continue;
        mt[a - 1] = i;
        nt[i] = a - 1;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] || nt[i] != -1)
            continue;
        dfs(i);
    }
    vector<int> lp_res, rp_res;
    for (int i = 0; i < n; i++)
        if (!lp[i])
            lp_res.push_back(i + 1);
    for (int i = 0; i < m; i++)
        if (rp[i])
            rp_res.push_back(i + 1);
    cout << (int)lp_res.size() + (int)rp_res.size() << "\n"
    << (int)lp_res.size() << " ";
    for (int i : lp_res)
        cout << i << " ";
    cout << "\n" << (int)rp_res.size() << " ";
    for (int i : rp_res)
        cout << i << " ";
    cout << "\n";
}
