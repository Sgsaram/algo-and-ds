pair<int, int> edge(int a, int b) {
    if (a > b)
        swap(a, b);
    return {a, b};
}

void findBridges(int v, int p = -1) {
    used[v] = true;
    if (p == -1)
        deep[v] = 0;
    else
        deep[v] = deep[p] + 1;
    up[v] = deep[v];
    for (int u : g[v]) {
        if (u == p)
            continue;
        if (!used[u]) {
            findBridges(u, v);
            up[v] = min(up[v], up[u]);
            if (up[u] > deep[v])
                bridges.insert(edge(v, u));
        }
        else
            up[v] = min(up[v], deep[u]);
    }
}