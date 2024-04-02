void dfs(int v) {
    used[v] = true;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
    t.push_back(v);
}

void top_sort() {
    for (int v = 0; v < n; v++)
        if (!used[v])
            dfs(v);
    reverse(t.begin(), t.end());
}