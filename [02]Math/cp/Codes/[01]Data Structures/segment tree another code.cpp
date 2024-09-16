const int MN = 100000 + 100;
struct seg_tree {
  int val[MN * 4 + 4];
  int pending[MN * 4 + 4];
  seg_tree() {
    memset(val, -1, sizeof val);
    memset(pending, -1, sizeof pending);
  }
  void propagate(int node, int b, int e) {
    if (pending[node] != -1) {
      val[node] = pending[node];
      if (b < e) {
        pending[node << 1] = pending[node];
        pending[node << 1 | 1] = pending[node];
      }
      pending[node] = -1;
    }
  }
  void set(int node, int b, int e, int from, int to, int v) {
    if (b > to || e < from) return;
    if (b >= from && e <= to) {
      pending[node] = v;
      propagate(node, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    set(node << 1, b, mid, from, to, v);
    set(node << 1 | 1, mid + 1, e, from, to, v);
  }
  int query(int node, int b, int e, int pos) {
    propagate(node, b, e);

    if (b == e && b == pos) {
      return val[node];
    }

    int mid = (b + e) >> 1;
    if (pos <= mid)
      return query(node << 1, b, mid, pos);
    return query(node << 1 | 1, mid + 1, e, pos);
  }

  void set(int from, int to, int v) {
    return set(1, 0, MN - 1, from, to, v);
  }

  int query(int pos) {
    return query(1, 0, MN - 1, pos);
  }
};

class segmentTree{
  using DT = long long;
  using LT = long long;
  int n;
  DT Tree[4 * N];
  LT I;
  DT merge(DT &a, DT &b){
    return max(a, b);
  }
  void build(int curLeft, int curRight, vector<LT> &v, int pos = 1){
    if(curLeft == curRight){
      Tree[pos] = v[curLeft]; return;
    }
    int mid = (curLeft + curRight) >> 1;
    build(curLeft, mid, v, pos << 1);
    build(mid + 1, curRight, v, pos << 1 | 1);
    Tree[pos] = merge(Tree[pos << 1], Tree[pos << 1 | 1]);
  }
  void update(int curLeft,int curRight, int idx, DT val, int pos = 1){ 
    if(curLeft == curRight){
      Tree[pos] = val; return;
    }
    int mid = (curLeft + curRight) >> 1;
    if(idx <= mid) update(curLeft, mid, idx, val, pos << 1);
    else update(mid + 1, curRight, idx, val, pos << 1 | 1);
    Tree[pos] = merge(Tree[pos << 1], Tree[pos << 1 | 1]);
  }
  int query(int curLeft, int curRight, int l, int r, int pos = 1){
    if(r < curLeft or l > curRight or l > r) return I;
    if(curLeft >= l and curRight <= r) return Tree[pos];
    int mid = (curLeft + curRight) >> 1;
    return merge(query(curLeft, mid, l, r, pos << 1) , query(mid + 1, curRight, l, r, pos << 1 | 1));
  }
  public:
    segmentTree(int _n, int _I, vector<int> &v){
      n = _n;
      I = _I;
      build(0, n - 1, v);
    }
    void update(int pos, int val){
      update(0, 0, n - 1, pos, val);
    }
    int query(int l, int r){
      return query(0, 0, n - 1, l, r);
    }
};
6. Segment Tree with Lazy Propagation
template<typename T1,typename T2>
//T1 is main array and T2 is the data type of segment tree
class segtree{
  private:
  int n;
  T2 (*seg);
  T2 identity;
  int *lazy;
  T2 merge(T2 a,T2 b){
    return max(a,b);
  }
  void propagate(int idx,int val,int le,int ri){//change propagate function accordingly
    seg[idx] += (ri-le+1)*val;
    if(le != ri){
      lazy[2*idx+1] += val;
      lazy[2*idx+2] += val;
    }
    lazy[idx] = 0;
  }
  void build(int idx,int le, int ri,T1 a[]){
    if(le==ri){
      seg[idx] = a[le];       //how the main array will affect the segment tree
      return;
    }
    int mid=(le+ri)/2;
    build(idx*2+1,le,mid,a);
    build(idx*2+2,mid+1,ri,a);
    seg[idx] = merge(seg[2*idx+1],seg[2*idx+2]);
  }
  void update(int idx,int le,int ri,int l,int r,int val){
    if(lazy[idx]) propagate(idx,lazy[idx],le,ri);
    if(r<le || l>ri) return;
    if(le>=l && ri<=r){
      propagate(idx,val,le,ri); return;
    }
    int mid=(le+ri)/2;
    update(idx*2+1,le,mid,l,r,val);
    update(idx*2+2,mid+1,ri,l,r,val);
    seg[idx] = merge(seg[2*idx+1],seg[2*idx+2]);
  }

  T2 query(int idx,int le,int ri,int l,int r){
    if(lazy[idx]){
        propagate(idx,lazy[idx],le,ri);
    }
    if(l<=le && r>=ri) return seg[idx];
    if(r<le || l>ri) return identity;
    int mid=(le+ri)/2;
    return merge(query(idx*2+1,le,mid,l,r) , query(idx*2+2,mid+1,ri,l,r));
  }
  public:
  segtree(T1 arr[],int m,,T2 Identity){
    n=m;
    identity = Identity;
    seg = new T2[n*4];
    lazy = new int[n*4];
    memset(lazy,0,sizeof(lazy));
    build(0,0,n-1,arr);
  }
  void update(int l,int r,int val){
    update(0,0,n-1,l,r,val);
  }
  T2 query(int l,int r){
    return query(0,0,n-1,l,r);
  }
};

template <typename VT>
struct segtree {
  using DT = typename VT::DT;
  using LT = typename VT::LT;
  int L, R;
  vector <VT> tr;
  segtree(int n): L(0), R(n - 1), tr(n << 2) {}
  segtree(int l, int r): L(l), R(r), tr((r - l + 1) << 2) {}
  void build(int l, int r, vector <DT> &v, int u = 1 ) {
    if(l == r) {
      tr[u].val = v[l];
      return;
    }
    int m = (l + r) >> 1, lft = u << 1, ryt = u << 1 | 1;
    build(l, m, v, lft);
    build(m + 1, r, v, ryt);
    tr[u].val = VT :: merge(tr[lft].val, tr[ryt].val, l, r);
  }
  void update(int ql,int qr, LT up, int l, int r, int u = 1) {
    if(ql > qr) return;
    if(ql == l and qr == r) {
      VT :: apply(tr[u], up, l, r);
      return;
    }
    int m = (l + r) >> 1, lft = u << 1, ryt = u << 1 | 1;
    update(ql, min(m, qr), up,  l,  m, lft);
    update(max(ql, m + 1), qr, up, m + 1, r, ryt);
    tr[u].val = VT :: merge(tr[lft].val, tr[ryt].val, l, r);
  }
  DT query(int ql, int qr, int l, int r, int u = 1) {
    if(ql > qr) return VT::I;
    if(l == ql and r == qr) return tr[u].val;
    int m = (l + r) >> 1, lft = u << 1, ryt = u << 1 | 1;
    DT ansl = query(ql, min(m, qr), l, m, lft);
    DT ansr = query(max(ql, m + 1), qr, m + 1, r, ryt);
    return tr[u].merge(ansl, ansr, l, r);
  }
  void build(vector <DT> &v) { build(L, R, v); }
  void update(int ql, int qr, LT U) { update(ql, qr, U, L, R); }
  DT query(int ql, int qr) { return query(ql, qr, L, R); }
};

/**************************************************************/
/*                 DON'T CHANGE ABOVE THIS                    */

struct add_sum {
  using DT = LL; // datatype of the nodes of segment tree
  using LT = LL; // datatype of the updates on the nodes
  DT val;
  static constexpr DT I = 0; // Identity of merge | answering query in empty range 
  add_sum(DT _val = I): val(_val) {}
  static void apply(add_sum &cur_node, const LT &updated_val, int l, int r) {
    cur_node.val += (r - l + 1) * updated_val;
  }
  static DT merge(const DT &a, const DT &b, int l, int r) {
    return a + b;
  }
};

Initialize under the main function: segtree <add_sum> Tree(n);
Operations: Tree.update(l, r, val), Tree.query(l, r);
