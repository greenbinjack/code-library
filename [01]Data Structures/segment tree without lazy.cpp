template <typename VT>
class segtree {
  using DT = typename VT :: DT;
  private:
    int L, R;
    vector <DT> tr;
  public:
    segtree (int n): L (0), R (n - 1), tr (n << 2) {}
    segtree (int l, int r): L (l), R (r), tr ((r - l + 1) << 2) {}
    void build (int curLeft, int curRight, vector <DT> &v, int pos = 1 ) {
      if (curLeft == curRight) {
        tr[pos] = v[curLeft];
        return;
      }
      int mid = (curLeft + curRight) >> 1, lft = pos << 1, ryt = pos << 1 | 1;
      build (curLeft, mid, v, lft);
      build (mid + 1, curRight, v, ryt);
      tr[pos] = VT :: merge (tr[lft], tr[ryt]);
    }
    void update (int curLeft, int curRight, DT updated_val, int idx, int pos = 1) {
      if (curLeft == curRight) {
        VT :: apply (tr[pos], updated_val);
        return;
      }
      int mid = (curLeft + curRight) >> 1, lft = pos << 1, ryt = pos << 1 | 1;
      if (idx <= mid) update (curLeft, mid, updated_val, idx, lft);
      else update (mid + 1, curRight, updated_val, idx, ryt);
      tr[pos] = VT :: merge (tr[lft], tr[ryt]);
    }
    DT query (int curLeft, int curRight, int l, int r, int pos = 1) {
      if (r < curLeft or l > curRight or l > r) return VT :: I;
      if (curLeft >= l and curRight <= r) return tr[pos];
      
      int mid = (curLeft + curRight) >> 1, lft = pos << 1, ryt = pos << 1 | 1;
      DT ansl = query (curLeft, mid, l, r, lft);
      DT ansr = query (mid + 1, curRight, l, r, ryt);
      return VT :: merge (ansl, ansr);
    }
    void build (vector <DT> &v) { build(L, R, v); }
    void update (int idx, DT U) { update (L, R, U, idx); }
    DT query (int ql, int qr) { return query(L, R, ql, qr); }
};

/**************************************************************/
/*                 DON'T CHANGE ABOVE THIS                    */

struct summation {
  using DT = LL; 
  static constexpr DT I = 0;
  static DT merge (const DT &a, const DT &b) {
    return a + b;
  }
  static void apply (DT &cur_node, const DT &updated_val) {
    cur_node = updated_val;
  }
};
struct node {
  int val, len;  
};
struct hashing {
  using DT = node; 
  static constexpr DT I = {0, 0};
  static DT merge (const DT &a, const DT &b) {
    DT ans;
    ans.val = (1LL * a.val * base[b.len] + b.val) % MOD;
    ans.len = a.len + b.len;
    return ans;
  }
  static void apply (DT &cur_node, const DT &updated_val) {
    cur_node = updated_val;
  }
};

struct minimum {
  using DT = LL; 
  static constexpr DT I = 1e18 + 69;
  static DT merge (const DT &a, const DT &b) {
    return min (a, b);
  }
  static void apply (DT &cur_node, const DT &updated_val) {
    cur_node = updated_val;
  }
};

struct maximum {
  using DT = LL; 
  static constexpr DT I = 0;
  static DT merge (const DT &a, const DT &b) {
    return max (a, b);
  }
  static void apply (DT &cur_node, const DT &updated_val) {
    cur_node = updated_val;
  }
};

struct xorsum {
  using DT = LL; 
  static constexpr DT I = 0;
  static DT merge (const DT &a, const DT &b) {
    return a ^ b;
  }
  static void apply (DT &cur_node, const DT &updated_val) {
    cur_node = updated_val;
  }
};

/* 
Initialize: segtree <add_sum> Tree (n); == 0-based indexing
            segtree <add_sum> Tree (1, n); == 1-based indexing
Operations: Tree.update (val, idx) == update idx index with val
            Tree.query (l, r); == query in range [l, r]
*/