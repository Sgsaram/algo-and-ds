vector<int>
prefix_function(string &s) {
	int n = s.size();
	vector<int> prefix(n, 0);
	for (int i = 1; i < n; ++i) {
		int k = prefix[i - 1];
		while (k > 0 && s[i] != s[k]) {
			k = prefix[k - 1];
		}
		if (s[i] == s[k]) {
			++k;
		}
		prefix[i] = k;
	}
	return prefix;
}