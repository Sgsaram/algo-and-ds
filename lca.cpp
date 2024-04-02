#include <bits/stdc++.h>

#define int long long

using namespace std;

int t = 0, k;
vector<vector<int>> g;
vector<int> tin, tout;
vector<int> used;
vector<vector<int>> up;

void dfs(int v) {
    for (int i = 1; i < k; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    tin[v] = t++;
    used[v] = true;
    for (int u : g[v])
        if (!used[u]) {
            up[u][0] = v;
            dfs(u);
        }
    tout[v] = t++;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}
int lca(int v, int u) {
    if (anc(v, u))
        return v;
    if (anc(u, v))
        return u;
    for (int i = k - 1; i >= 0; i--)
        if (!anc(up[v][i], u))
            v = up[v][i];
    return up[v][0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y, z;
    cin >> n >> m;
    k = __lg(n) + 1;
    tin.resize(n);
    tout.resize(n);
    used.resize(n);
    up.resize(n, vector<int>(k));
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int from;
        cin >> from;
        g[from].push_back(i + 1);
        g[i + 1].push_back(from);
    }
    dfs(0);
}







// SUM





#include <bits/stdc++.h>

#define int long long

using namespace std;

int t = 0, k;
vector<vector<int>> g, up, s;
vector<int> tin, tout, val;
vector<bool> used;

void dfs(int v) {
    s[v][0] = val[v];
    for (int i = 1; i < k; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
        if (up[v][i] == up[v][i - 1])
            s[v][i] = s[v][i - 1];
        else
            s[v][i] = s[v][i - 1] + s[up[v][i - 1]][i - 1];
    }
    tin[v] = t++;
    used[v] = true;
    for (int u : g[v])
        if (!used[u]) {
            up[u][0] = v;
            dfs(u);
        }
    tout[v] = t++;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tin[u] < tout[v];
}

int get_sum(int a, int b) {
    int res = 0;
    for (int i = k - 1; i >= 0; i--)
        if (!anc(up[a][i], b)) {
            res += s[a][i];
            a = up[a][i];
        }
    return res + s[a][0] + s[b][0] * (a != b);
}

int lca_sum(int a, int u) {
    int v = a;
    if (anc(v, u))
        return get_sum(u, v);
    if (anc(u, v))
        return get_sum(v, u);
    for (int i = k - 1; i >= 0; i--)
        if (!anc(up[v][i], u))
            v = up[v][i];
    return get_sum(a, up[v][0]) + get_sum(u, up[v][0]) - s[up[v][0]][0];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n;
    k = __lg(n) + 1;
    tin.resize(n);
    tout.resize(n);
    used.resize(n);
    val.resize(n);
    up.resize(n, vector<int>(k));
    s.resize(n, vector<int>(k));
    g.resize(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    dfs(0);
    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << lca_sum(a - 1, b - 1) << "\n";
    }
}



// MIN EDGE




#include <bits/stdc++.h>

#define int long long

using namespace std;

const int INF = 1e13 + 7;

int t = 0, k;
vector<vector<int>> g, up, min_lca;
vector<int> tin, tout, p;

void dfs(int v) {
    min_lca[v][0] = p[v];
    for (int i = 1; i < k; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
        min_lca[v][i] = min(min_lca[v][i - 1], min_lca[up[v][i - 1]][i - 1]);
    }
    tin[v] = t++;
    for (int u : g[v]) {
        up[u][0] = v;
        dfs(u);
    }
    tout[v] = t++;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tin[u] < tout[v];
}

int get_min(int a, int b) {
    int res = INF;
    for (int i = k - 1; i >= 0; i--)
        if (!anc(up[a][i], b)) {
            res = min(res, min_lca[a][i]);
            a = up[a][i];
        }
    return min(res, min_lca[a][0]);
}

int lca_min(int a, int u) {
    int v = a;
    if (anc(v, u))
        return get_min(u, v);
    if (anc(u, v))
        return get_min(v, u);
    for (int i = k - 1; i >= 0; i--)
        if (!anc(up[v][i], u))
            v = up[v][i];
    return min(get_min(a, up[v][0]), get_min(u, up[v][0]));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n;
    k = __lg(n) + 1;
    tin.resize(n);
    tout.resize(n);
    up.resize(n, vector<int>(k));
    min_lca.resize(n, vector<int>(k));
    g.resize(n);
    p.resize(n);
    p[0] = INF;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a - 1].push_back(i);
        p[i] = b;
    }
    dfs(0);
    cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << lca_min(a - 1, b - 1) << "\n";
    }
}
