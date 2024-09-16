LL bigmod(LL x, LL n, LL mod) {
  if(n == -1) n = mod - 2;
  LL ans = 1;
  while(n) {
    if((n & 1)) ans = (ans * x) % mod;
    n >>= 1;
    x = (x * x) % mod;
  }
  return ans;
}