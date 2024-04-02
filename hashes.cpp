class Hasher {
private:
    int n;
    string s;
    vector<int> p, pref_hash;
public:
    Hasher(const string &s) : n((int)s.size()), s(s) {
        p.resize(n + 1);
        pref_hash.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++)
            p[i] = (p[i - 1] * K) % MOD;
        for (int i = 1; i <= n; i++)
            pref_hash[i] = (pref_hash[i - 1] * K + s[i - 1] - 'a' + 1) % MOD;
    }

    int get_hash(int l, int r) {
        return ((pref_hash[r] - pref_hash[l] * p[r - l]) % MOD + MOD) % MOD;
    }
};