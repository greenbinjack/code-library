#define lg(x) (31 - __builtin_clz(x))
template <typename VT> class sparseTable {
  using DT = typename VT :: DT;
  private:
    int N, K;
    vector < vector <DT> > tr;
  public:
    sparseTable (const vector <DT> &v) {
      N = v.size ();
      K = lg (N);
      tr.resize (N, vector <DT> (K + 1));
      for (int i = 0; i < N; i++) tr[i][0] = v[i];
      for(int j = 1; j <= K; j++) {
        for(int i = 0; i + (1 << j) <= N; i++)
          tr[i][j] = VT :: merge (tr[i][j - 1], tr[i + (1 << (j - 1))][j - 1]);
      }
    }
    DT query (int l, int r) {
      int d = lg (r - l + 1);
      return VT :: merge (tr[l][d], tr[r - (1 << d) + 1][d]);
    }
};

struct summation {
  using DT = LL; 
  static DT merge (const DT &a, const DT &b) {
    return a + b;
  }
};

struct minimum {
  using DT = LL; 
  static DT merge (const DT &a, const DT &b) {
    return min (a, b);
  }
};

struct maximum {
  using DT = LL; 
  static DT merge (const DT &a, const DT &b) {
    return max (a, b);
  }
};

struct xorsum {
  using DT = LL; 
  static DT merge (const DT &a, const DT &b) {
    return a ^ b;
  }
};