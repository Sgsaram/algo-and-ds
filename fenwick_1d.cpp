#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
vector<int> t, a;

void add(int i, int v) {
    int d = (v - a[i]);
    a[i] = v;
    while (i <= n) {
        t[i] += d;
        i |= (i + 1);
    }
}

int sum(int i) {
    int res = 0;
    while (i >= 0) {
        res += t[i];
        i = (i & (i + 1)) - 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, i, x, l, r;
    cin >> n >> k;
    t.resize(n + 1);
    a.resize(n + 1);
    char req;
    while (k--) {
        cin >> req;
        if (req == 'A') {
            cin >> i >> x;
            add(i, x);
        }
        else {
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << "\n";
        }
    }
}