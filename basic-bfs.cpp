vector<int> bfs(int s) {
    vector<int> dist(n, INF);
    d[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }

    return dist;
}