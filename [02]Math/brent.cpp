
using ULLL = unsigned __int128;
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1); 
mt19937_64 rng(SEED);
LL brent (LL n) {
  if (n % 2 == 0) return 2;
  LL y = rng() % (n - 1) + 1;
  LL c = rng() % (n - 1) + 1;
  LL m = rng() % (n - 1) + 1;
  LL g = 1, r = 1, q = 1, ys, x;
  while (g == 1) {
    x = y;
    for (int i = 0; i < r; i++) y = ((ULLL)y * y + c) % n;
    LL k = 0;
    while ( k < r && g == 1 ) {
      ys = y;
      for (int i = 0; i < min(m, r - k); i++) {
        y = ((ULLL)y * y + c) % n;
        q = ((ULLL)q * abs(x - y)) % n;
      } g = __gcd(q, n); k = k + m;
    } r *= 2;
  }
  if (g == n) {
    while (true) {
      ys = ((ULLL)ys * ys + c) % n;
      g = __gcd(abs(x - ys), n);
      if (g > 1) break;
    }
  } return g;
}
