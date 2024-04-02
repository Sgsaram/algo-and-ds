void bfs(int v) {
    dist[v] = 0;
    deque<int> q;
    q.push_back(v);
    while (!q.empty()) {
        v = q[0];
        q.pop_front();
        for (auto [u, w] : g[v]) {
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                if (w == 0)
                    q.push_front(u);
                else
                    q.push_back(u);
            }
        }
    }
}
