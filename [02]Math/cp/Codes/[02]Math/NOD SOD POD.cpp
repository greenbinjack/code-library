// NUMBER = p_1^a_1 * p_2^a_2 .... p_n^a_n
LL NOD = 1, SOD = 1, POD = 1, POWER = 1;
for(int i = 0; i < n; i++) {
  LL p, a; cin >> p >> a; 
  NOD = (NOD * (a + 1)) % MOD;
  SOD = ((SOD * (bigmod(p, a + 1, MOD) + MOD - 1)) % MOD * inv[p - 1]) % MOD;
  POD = bigmod(POD, a + 1, MOD) * bigmod(bigmod(x, a * (a + 1) / 2, MOD), POWER, MOD) % MOD;
  POWER = (POWER * (a + 1)) % (MOD - 1);
}
cout << NOD << ' ' << SOD << ' ' << POD << '\n';
// FULL TEMPLATE
using LL = long long;
using ULL = unsigned long long;
namespace sieve{
  const int N = 1e7;
  vector <int> primes;
  int spf[N+5], phi[N+5], NOD[N+5], cnt[N+5], POW[N+5]; 
  bool prime[N+5];
  int SOD[N+5];
  void init(){
   fill(prime+2, prime+N+1, 1);
   SOD[1] = NOD[1] = phi[1] = spf[1] = 1;
   for(LL i=2;i<=N;i++){
    if(prime[i]) {
    primes.push_back(i), spf[i] = i;
    phi[i] = i-1;
    NOD[i] = 2, cnt[i] = 1;
    SOD[i] = i+1, POW[i] = i;
   }
   for(auto p:primes){
    if(p*i>N or p > spf[i]) break;
    prime[p*i] = false, spf[p*i] = p;
    if(i%p == 0){
    phi[p*i]=p*phi[i];
    NOD[p*i]=NOD[i]/(cnt[i]+1)*(cnt[i]+2), cnt[p*i]=cnt[i]+1;
    SOD[p*i]=SOD[i]/SOD[POW[i]]*(SOD[POW[i]]+p*POW[i]),POW[p*i]=p*POW[i];
    break;
   } else {
      phi[p*i]=phi[p]*phi[i];
      NOD[p*i]=NOD[p]*NOD[i], cnt[p*i]=1;
      SOD[p*i]=SOD[p]*SOD[i], POW[p*i]=p;
   }
} } }
  // O(lg n factorization for small numbers upto sieve)
  map <ULL,int> fast_factorize(ULL n){
    map <ULL,int> ans;
    for(;n>1;n/=spf[n]) ans[spf[n]]++;
    return ans;
  }
  // factorization for big numbers
  // using pollard rho might be better
  map <ULL,int> factorize(ULL n){
    int cnt = 0;
    map <ULL,int> ans;
    for(auto p:primes){
      if(p*p>n) break;
      for(;n%p==0;n/=p) ans[p]++;
    }
    if(n!=1) ans[n]++;
    return ans;
  }
  // only for large numbers
  int number_of_div(ULL n){
    if(n < 1) return 0;
    auto A = factorize(n);
    int ans = 1;
    for(auto [p,cnt]:A) ans *= cnt+1;
    return ans;
  }
  ULL sum_of_div(ULL n){
    if(n < 1) return 0;
    ULL ans = 1, ppow;
    for(ULL p:primes){
      if(p*p > n) break;
      for(ppow=p; n%p==0; n/=p,ppow*=p);
      ans *=(ppow-1)/(p-1);
    }
    return n == 1 ? ans: ans*(1+n);
  }
  ULL PHI(ULL n){
    ULL ans = n;
    for(auto [p,cnt]:factorize(n)) ans = ans/p*(p-1); 
    return ans;
  }
}
// CSOD
LL csod(LL n) {
  LL ans = 0;
  for(LL i = 2; i * i <= n; ++i) {
    LL j = n / i;
    ans += (i + j) * (j - i + 1) / 2;
    ans += i * (j - i);
  }
  return ans;
}
summation of NOD(d)[d|n] = product of g(e_k + 1)[n=p_k^a_k]
g(x) = x * (x + 1) / 2
