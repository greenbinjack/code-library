int n = 20;
vector<int> a(1 << n);
// keeps track of the sum over subsets
// with a certain amount of matching bits in the prefix
vector<vector<int>> dp(1 << n, vector<int>(n));
vector<int> sos(1 << n);
for (int mask = 0; mask < (1 << n); mask++) {
	dp[mask][-1] = a[mask];
	for (int x = 0; x < n; x++) {
		dp[mask][x] = dp[mask][x - 1];
		if(CHECK(mask, x)) { dp[mask][x] += dp[mask - (1 << x)][x - 1]; }
	}
	sos[mask] = dp[mask][n - 1];
}
//memory optimized, super easy to code.
for(int i = 0; i < (1 << n); ++i) sos[i] = a[i];
for(int i = 0;i < n; i++) {
	for(int mask = 0; mask < (1 << n); mask+=){
		if(CHECK(mask, i)) sos[mask] += sos[mask ^ (1 << i)];
	}
}