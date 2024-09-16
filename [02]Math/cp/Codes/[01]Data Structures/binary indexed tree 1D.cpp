template <typename DT> class BIT {
  public:
    vector <DT> tree; 
    int n;
  BIT(int n) {
    this->n = n;
    tree.assign(n, 0);
  }
  BIT(const vector <DT> &a) : BIT(a.size()) {
    for (int i = 0; i < n; i++) add(i, a[i]);
  }
  DT sum(int r) {
    DT ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += tree[r];
    return ret;
  }
  DT sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
  void add(int idx, DT delta) {
    for (; idx < n; idx = idx | (idx + 1)) tree[idx] += delta;
  } 
};
// BIT<LL> pref(mxN);