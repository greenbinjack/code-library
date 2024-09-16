void coin_combi_I(vector<int> &v, int W) {
  dp[0] = 1;
  for(int w = 1; w <= W; w++) {
    for(auto cur : v) {
      if(cur > w) continue;
      dp[w] = (dp[w] + dp[w - cur]) % MOD;
    }
  }
  return dp[W]
}
// ordered ways
void coin_combi_II(vector<int> &v, int W) {
  dp[0] = 1;
  for(auto cur : v) {
    for(int w = cur; w <= W; w++) {
      if(cur > w) continue;
      dp[w] = (dp[w] + dp[w - cur]) % MOD;
    }
  }
  return dp[W];
}
