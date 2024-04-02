#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> mt;

bool kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int u : g[v]) {
        if (mt[u] == -1 || kuhn(mt[u])) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, res = 0;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    mt.resize(m, -1);
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (a != 0) {
            g[i].push_back(a - 1);
            cin >> a;
        }
    }
    for (int i = 0; i < n; i++) {
        used.assign(n, false);
        if (kuhn(i))
            res++;
    }
    cout << res << "\n";
    for (int i = 0; i < m; i++) {
        if (mt[i] == -1)
            continue;
        cout << mt[i] + 1 << " " << i + 1 << "\n";
    }
}