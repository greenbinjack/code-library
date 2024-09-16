namespace COMBI_starter{
  LL fact[N], inv[N], inv_fact[N];
  void init(){
    fact[0] = inv_fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++){
      inv[i] = i == 1 ? 1 : (LL) inv[i - MOD % i] * (MOD / i + 1) % MOD;
      fact[i] = (LL) fact[i - 1] * i % MOD;
      inv_fact[i] = (LL) inv_fact[i - 1] * inv[i] % MOD;
    }
  }
  LL nCr (LL n, LL r){
    return (r < 0 or r > n) ? 0 : fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
  }
}