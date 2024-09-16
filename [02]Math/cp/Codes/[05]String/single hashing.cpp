class HashedString {
  private:
  static const LL M = (1LL << 61) - 1;
  static const LL B;
  static vector<LL> pow;
  vector<LL> p_hash;

  __int128 mul(LL a, LL b) { return (__int128)a * b; }
  LL mod_mul(LL a, LL b) { return mul(a, b) % M; }

  public:
  HashedString(const string &s) : p_hash(s.size() + 1) {
    while (pow.size() < s.size()) { 
        pow.push_back(mod_mul(pow.back(), B)); 
    }
    p_hash[0] = 0;
    for (int i = 0; i < s.size(); i++) {
      p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
    }
  }
  LL get_hash(int start, int end) {
    LL raw_val =
        p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
    return (raw_val + M) % M;
  }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<LL> HashedString::pow = {1};
const LL HashedString::B = uniform_int_distribution<LL>(0, M - 1)(rng);
