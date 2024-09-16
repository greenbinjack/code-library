vector <bool> prime;
vector <LL> primes,phi;

void seive(LL n = 1e7+3){
  prime.assign(n+1,true), phi.resize(n+1);
  phi[1] = 1;
  for(LL i=2;i<=n;i++){
    if(prime[i]) {
      phi[i] = i-1;
      primes.push_back(i);
    }
  for(auto p:primes){
    if(p*i>n)   break;
    prime[p*i] = false;
    if(i%p == 0){
      phi[p*i] = p*phi[i];
      break;
    } else {
      phi[p*i] = phi[p] * phi[i];
    }
  } }
}
phi(a*b) = phi(a)*phi(b)*(gcd(a,b)/phi(gcd(a,b))) ,for any number
phi(p^k) = p^k - p^(k-1) ,where p is a prime number, ’^’ indicates power
Sum of values of totient functions of all divisors of n is equal to n.
