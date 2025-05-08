struct AP { // Arithmetic Progression: a, a + d, a + 2d, ...
  LL a = 0, d = 0;
  AP() = default;
  AP(LL _a, LL _d) : a(_a), d(_d) {}
  LL at(LL n) const { return a + (n - 1) * d; }
  AP shift(LL n) const { return AP(a + (n - 1) * d, d); }
  LL get_sum(LL n) const { return ((2 * a + (n - 1) * d) * n) / 2; }
  AP operator+(const AP &other) const { return AP(a + other.a, d + other.d); }
};

template <typename DT, typename LT>
class segtree {
private:
  vector<DT> tree;
  vector<LT> lazy;
  int L, R;

  void push (int pos, int curLeft, int curRight) {
    if (lazy[pos].a == 0 && lazy[pos].d == 0) return;
    tree[pos] += lazy[pos].get_sum(curRight - curLeft + 1);
    int mid = (curLeft + curRight) >> 1, lft = pos << 1, ryt = lft | 1;
    if (curLeft != curRight) {
      lazy[lft] = lazy[lft] + lazy[pos];
      lazy[lft | 1] = lazy[ryt] + lazy[pos].shift(mid + 2 - curLeft);
    }
    lazy[pos] = LT();
  }

  void build(int pos, int curLeft, int curRight, const vector<DT> &a) {
    lazy[pos] = LT();
    if (curLeft == curRight) {
      tree[pos] = a[curLeft];
      return;
    }
    int mid = (curLeft + curRight) >> 1, lft = pos << 1, ryt = lft | 1;
    build(lft, curLeft, mid, a);
    build(ryt, mid + 1, curRight, a);
    tree[pos] = tree[lft] + tree[ryt];
  }

  void update(int pos, int curLeft, int curRight, int  ql, int qr, LT up) {
    push(pos, curLeft, curRight);
    if (curLeft > qr or curRight < ql) return;
    if (ql <= curLeft and curRight <= qr) {
      lazy[pos] = lazy[pos] + up.shift(curLeft - ql + 1);
      push(pos, curLeft, curRight);
      return;
    }
    int mid = (curLeft + curRight) >> 1, lft = pos << 1, ryt = lft | 1;
    update(lft, curLeft, mid,  ql, qr, up);
    update(ryt, mid + 1, curRight,  ql, qr, up);
    tree[pos] = tree[lft] + tree[ryt];
  }

  DT query(int pos, int curLeft, int curRight, int  ql, int qr) {
    push(pos, curLeft, curRight);
    if (curLeft > qr or curRight <  ql) return 0;
    if (ql <= curLeft and curRight <= qr) return tree[pos];
    int mid = (curLeft + curRight) >> 1, lft = pos << 1, ryt = lft | 1;
    return query(lft, curLeft, mid,  ql, qr) + query(ryt, mid + 1, curRight, ql, qr);
  }

public:
  segtree(int N) : L(0), R(N - 1), tree(N << 2, DT ()), lazy(N << 2, LT()) {}
  segtree(int b, int e) : L(b), R(e), tree((e - b + 1) << 2, DT ()), lazy((e - b + 1) << 2, LT()) {}
  void build(const vector<DT> &a) { build(1, L, R, a); }
  void update(int l, int r, LT up) { update(1, L, R, l, r, up); }
  DT query(int l, int r) { return query(1, L, R, l, r); }
};