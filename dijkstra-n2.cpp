vector<int> dijkstra(int s) {
    vector<int> d(n, inf), a(n, 0);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int u = 0; u < n; u++)
            if (!a[u] && (v == -1 || d[u] < d[v]))
                v = u;
        a[v] = true;
        for (auto [u, w] : g[v])
            d[u] = min(d[u], d[v] + w);
    }
    return d;
}
