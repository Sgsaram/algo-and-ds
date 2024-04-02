void topSort(int v) {
    used[v] = true;
    for (int u : g[v])
        if (!used[u])
            topSort(u);
    ord.push_back(v);
}

void dfs(int v, int c) {
    comp[v] = c;
    for (int u : gr[v])
        if (comp[u] == -1)
            dfs(u, c);
}

int main() {
    for (int i = 0; i < n; i++)
        if (!used[i])
            topSort(i);
    reverse(ord.begin(), ord.end());
    int c = 0;
    for (int i : ord)
        if (comp[i] == -1)
            dfs(i, c++);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++)
            if (comp[i] != comp[g[i][j]])
                s.insert({comp[i], comp[g[i][j]]});
}