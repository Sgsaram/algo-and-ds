for (int i = 0; i < n; i++)
    for (int v = 0; v < n; v++)
        for (int u = 0; u < n; u++)
            if (d[v][i] + d[i][u] < d[v][u]) {
                d[v][u] = d[v][i] + d[i][u];
                next[v][u] = next[v][i];
            }
           	
void get_path(int v, int u) {
    if (d[v][u] == INF) {
        cout << "No path\n";
        return;
    }
    int c = v;
    while (c != u) {
        cout << c << " ";
        c = next[c][u];
    }
    cout << u << "\n";
}