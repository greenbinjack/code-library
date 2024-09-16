const int MAX = 1e8 + 7;
int prime[(MAX >> 5) + 2];
vector<int> primes;
void sieve() {
  int lim = sqrt(MAX);
  for(int i = 3; i <= lim; i += 2) {
    if(!CHECK(prime[i >> 5], i & 31)) {
      for(int j = i * i; j <= MAX; j += (i << 1)) 
        SET(prime[j >> 5],j & 31);
    }
  }
  primes.push_back(2);
  for(int i = 3; i <= MAX; i += 2) {
    if(!Check(prime[i >> 5],i & 31)) primes.push_back(i);
  }
}