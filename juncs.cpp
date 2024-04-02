void findJuncs(int v, int p = -1) {
    int child = 0;
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
            findJuncs(u, v);
            up[v] = min(up[v], up[u]);
            if (deep[v] <= up[u] && p != -1)
                juncs.insert(v + 1);
            child++;
        }
        else
            up[v] = min(up[v], deep[u]);
    }
    if (p == -1 && child > 1)
        juncs.insert(v + 1);
}