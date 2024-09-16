template <LL mod> struct INT_MOD {
  LL val;
  INT_MOD(LL val = 0): val(val >= 0 ? val % mod : val % mod + mod) {}
  INT_MOD operator + (INT_MOD rhs) const { return INT_MOD((val + rhs.val)); }
  INT_MOD operator - (INT_MOD rhs) const { return INT_MOD((val - rhs.val)); }
  INT_MOD operator * (INT_MOD rhs) const { return INT_MOD((val * rhs.val)); }
  INT_MOD operator / (INT_MOD rhs) const { return INT_MOD( binpow(rhs, mod - 2) * val);}
  void operator += (INT_MOD rhs) { *this = *this + rhs; }
  void operator -= (INT_MOD rhs) { *this = *this - rhs; }
  void operator *= (INT_MOD rhs) { *this = *this * rhs; }
  void operator /= (INT_MOD rhs) { *this = *this / rhs; }
  friend INT_MOD binpow (INT_MOD val, LL p) {
    INT_MOD ans = 1;
    for (; p > 0; p >>= 1, val *= val) if (p & 1) ans = ans * val;
    return ans;
  }
  friend ostream& operator << (ostream& o, INT_MOD &a) {
    o << a.val; return o;
  }
  friend istream& operator >> (istream& o, INT_MOD &a) {
    o >> a.val; return o;
  }
  friend LL abs(INT_MOD a) {
    return abs(a.val);
  }
};