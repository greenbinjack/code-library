using PLL = pair <LL,LL>;
// given a, b will find solutions for
// ax + by = 1
tuple <LL,LL,LL> EGCD(LL a, LL b){
  if(b == 0) return {1, 0, a};
  else{
    auto [x,y,g] = EGCD(b, a%b);
    return {y, x - a/b*y,g};
  }
}
// given modulo equations, will apply CRT
PLL CRT(vector <PLL> &v){
  LL V = 0, M = 1;
  for(auto &[v, m]:v){ //value % mod
    auto [x, y, g] = EGCD(M, m);
    if((v - V) % g != 0) return {-1, 0};
    V += x * (v - V) / g % (m / g) * M, M *= m / g;
    V = (V % M + M) % M;
  }
  return make_pair(V, M);
}


// new one added

template <typename T>
T egcd(T a, T b, T &x, T &y) {
    T xx = 0, y = 0;
    T yy = 1, x = 1;
    while (b) {
        T q = a / b;
        T t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

// Finds x such that x % m1 = a1, x % m2 = a2. m1 and m2 may not be coprime.
// Here, x is unique modulo m = lcm(m1, m2). Returns (x, m). On failure, m = -1.
template <typename T>
pair<T, T> crt(T a1, T m1, T a2, T m2) {
    if (m1 == -1 || m2 == -1) return make_pair(0, -1);
    
    T p, q;
    T g = egcd(m1, m2, p, q);
    if (a1 % g != a2 % g) return make_pair(0, -1);
    
    T m = m1 / g * m2;
    p = (p % m + m) % m;
    q = (q % m + m) % m;
    
    return make_pair((p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) % m, m);
}
