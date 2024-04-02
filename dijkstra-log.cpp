void dijkstra(int s, const vector<vector<pair<int, int>>> &g, vector<int> &d, vector<int> &p) {
    int n = (int)d.size(), v;
    d.assign(n, INF);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({d[s], s});
    while (!q.empty()) {
        v = q.begin()->second;
        q.erase(q.begin());
        for (auto [u, w] : g[v]) {
            if (d[v] + w < d[u]) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                p[u] = v;
                q.insert({d[u], u});
            }
        }
    }
}

void get_path(int s, int v, vector<int> &p, vector<int> &res) {
    while (v != s) {
        res.push_back(v);
        v = p[v];
    }
    res.push_back(v);
    reverse(res.begin(), res.end());
}