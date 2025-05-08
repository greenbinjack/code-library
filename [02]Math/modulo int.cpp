template <LL mod> struct mint {
  LL val;
  mint(LL val = 0): val(val >= 0 ? val % mod : val % mod + mod) {}
  mint operator + (mint rhs) const { return mint((val + rhs.val)); }
  mint operator - (mint rhs) const { return mint((val - rhs.val)); }
  mint operator * (mint rhs) const { return mint((val * rhs.val)); }
  mint operator / (mint rhs) const { return mint( binpow(rhs, mod - 2) * val);}
  void operator += (mint rhs) { *this = *this + rhs; }
  void operator -= (mint rhs) { *this = *this - rhs; }
  void operator *= (mint rhs) { *this = *this * rhs; }
  void operator /= (mint rhs) { *this = *this / rhs; }
  friend mint binpow (mint val, LL p) {
    mint ans = 1;
    for (; p > 0; p >>= 1, val *= val) if (p & 1) ans = ans * val;
    return ans;
  }
  friend ostream& operator << (ostream& o, mint &a) {
    o << a.val; return o;
  }
  friend istream& operator >> (istream& o, mint &a) {
    o >> a.val; return o;
  }
  friend LL abs(mint a) {
    return abs(a.val);
  }
};

