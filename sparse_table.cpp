
int get_min(int l, int r) { // [l, r)
    int k = __lg(r - l);
    return min(table[k][l], table[k][r - (1 << k)]);
}


k = __lg(n) + 1;
table.resize(k, vector<int>(n));
for (int i = 0; i < n; i++)
    table[0][i] = a[i];
for (int i = 1; i < k; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
        table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);