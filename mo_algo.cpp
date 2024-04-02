#include <bits/stdc++.h>

#define int long long

using namespace std;

int k;

struct Req {
    int l = 0, r = 0, id = 0;

    bool operator <(Req b) const {
        if (l / k != b.l / k)
            return l < b.l;
        return r < b.r;
    }
};

int cnt[300007] = {};

void add(int i, int &res) {
    if (cnt[i] == 0)
        res++;
    cnt[i]++;
}

void remove(int i, int &res) {
    assert(cnt[i] > 0);
    if (cnt[i] == 1)
        res--;
    cnt[i]--;
}

void compress(vector<int> &a) {
    set<int> st;
    map<int, int> mp;
    for (int i : a)
        st.insert(i);
    int c = 0;
    for (long long i : st)
        mp[i] = c++;
    for (int &i : a)
        i = mp[i];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    k = (int)sqrt(n) + 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    compress(a);
    cin >> m;
    vector<int> res(m);
    vector<Req> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--, q[i].r--;
        q[i].id = i;
    }
    sort(q.begin(), q.end());
    int cl = 1, cr = 0, l, r, ans = 0;
    for (int i = 0; i < m; i++) {
        l = q[i].l;
        r = q[i].r;
        while (cl > l)
            add(a[--cl], ans);
        while (cr < r)
            add(a[++cr], ans);
        while (cl < l)
            remove(a[cl++], ans);
        while (cr > r)
            remove(a[cr--], ans);
        res[q[i].id] = ans;
    }
    for (int i : res)
        cout << i << "\n";
}