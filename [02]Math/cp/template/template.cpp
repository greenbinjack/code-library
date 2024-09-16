// Segment tree with lazy - update - subarray sum
void updateRange(LL node, LL curLeft, LL curRight, LL l, LL r, LL val)
{
    if(lazy[node] != 0)
    {
        tree[node] += lazy[node];
        if(curLeft != curRight) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(curLeft > curRight or curLeft > r or curRight < l) return;
    if(curLeft >= l and curRight <= r) {
        tree[node] += val;
        if(curLeft != curRight) {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    LL mid = (curLeft + curRight) / 2;
    updateRange(node*2, curLeft, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, curRight, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}

LL queryRange(LL node, LL curLeft, LL curRight, LL l, LL r)
{
    if(curLeft > curRight or curLeft > r or curRight < l) return 0;
    if(lazy[node] != 0) {
        tree[node] += lazy[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(curLeft >= l and curRight <= r) return tree[node];
    LL mid = (curLeft + curRight) / 2;
    LL sumL = queryRange(node*2, curLeft, mid, l, r);         // Query left child
    LL sumR = queryRange(node*2 + 1, mid + 1, curRight, l, r); // Query right child
    return (sumL + sumR);
}

// another example with lazy
struct node {
  LL le, ri;
  bool is_good;

};
std::vector<node> segTree(4 * N);
std::vector<LL> lazy(4 * N, 0);
LL n;
string s;
void updt(LL pos) {
  bool ok = segTree[pos * 2].is_good & segTree[pos * 2 + 1].is_good;
  if(segTree[pos * 2].ri == segTree[pos * 2 + 1].le) ok = false;
  segTree[pos] = {segTree[pos * 2].le, segTree[pos * 2 + 1].ri, ok};
}
void build(LL curLeft, LL curRight, LL pos) {
  if(curLeft == curRight) {
    int x = s[curLeft] - '0';
    segTree[pos] = {x, x, 1};
    return;
  }
  LL mid = (curLeft + curRight) / 2;
  build(curLeft, mid, pos * 2);
  build(mid + 1, curRight, pos * 2 + 1);
  updt(pos);
}
void apply(LL curLeft, LL curRight, LL pos) {
  if(lazy[pos] % 2) {
    auto cur = segTree[pos];
    segTree[pos] = {1 - cur.le, 1 - cur.ri, cur.is_good};
    if(curLeft != curRight) {
      lazy[pos * 2] += lazy[pos];
      lazy[pos * 2 + 1] += lazy[pos];
    }
  }
  lazy[pos] = 0;
}
void updateRange(LL curLeft, LL curRight, LL pos, LL l, LL r, LL val) {
  apply(curLeft, curRight, pos);
  if(curLeft > curRight or curLeft > r or curRight < l) return;
  if(curLeft >= l and curRight <= r) {
    auto cur = segTree[pos];
    segTree[pos] = {1 - cur.le, 1 - cur.ri, cur.is_good};
    if(curLeft != curRight) {
      lazy[pos * 2] += val;
      lazy[pos * 2 + 1] += val;
    }
    return;
  }
  LL mid = (curLeft + curRight) / 2;
  updateRange(curLeft, mid, pos * 2, l, r, val);       
  updateRange(mid + 1, curRight, pos * 2 + 1, l, r, val);   
  updt(pos);   
}
node queryRange(LL curLeft, LL curRight, LL pos, LL l, LL r) {
  if(curLeft > curRight or curLeft > r or curRight < l) return {-1, -1, 0};
  apply(curLeft, curRight, pos);
  if(curLeft >= l and curRight <= r) return segTree[pos];
  LL mid = (curLeft + curRight) / 2;
  node Left = queryRange(curLeft, mid, pos * 2, l, r);         
  node Right = queryRange(mid + 1, curRight, pos * 2 + 1, l, r); 
  if(Left.le == -1) return Right;
  if(Right.le == -1) return Left;
  bool ok = Left.is_good & Right.is_good;
  if(Left.ri == Right.le) ok = false;
  return {Left.le, Right.ri, ok};
}

// segment tree without lazy - to find sum in [l, r] with updates at[pos, val]

LL n, segTree[4 * MAXN], v[MAXN];
void build(LL curLeft, LL curRight, LL pos)
{
    if(curLeft == curRight) {
        segTree[pos] = v[curLeft];
        return;
    }
    LL mid = (curLeft + curRight) / 2;
    build(curLeft, mid, pos * 2);
    build(mid + 1, curRight, pos * 2 + 1);
    segTree[pos] = segTree[pos * 2] + segTree[pos * 2 + 1];
}
void update(LL curLeft, LL curRight, LL target_idx, LL pos)
{
    if(curLeft == curRight) {
        segTree[pos] = v[curLeft];
        return;
    }
    LL mid = (curLeft + curRight) / 2;
    if(target_idx <= mid) update(curLeft, mid, target_idx, pos * 2);
    else update(mid + 1, curRight, target_idx, pos * 2 + 1);
    segTree[pos] = segTree[pos * 2] + segTree[pos * 2 + 1];
}
LL query(LL curLeft, LL curRight, LL low, LL high, LL pos)
{
    if(low > curRight or high < curLeft or curRight < curLeft) return 0;
    if(curLeft >= low and curRight <= high) return segTree[pos];
    LL mid = (curLeft + curRight) / 2;
    LL sumL = query(curLeft, mid, low, high, pos * 2);
    LL sumR = query(mid + 1, curRight, low, high, pos * 2 + 1);
    return (sumL + sumR);
}

// SEGMENT TREE - RANGE UPDATE POINT QUERY

LL lazy[4 * MAXN];
void update(LL curLeft, LL curRight, LL low, LL high, LL val, LL pos)
{
    if(curLeft >= low and high >= curRight) {
        lazy[pos] += val;
        return;
    }
    if(lazy[pos] && curLeft != curRight) {
        lazy[pos * 2] += lazy[pos];
        lazy[pos * 2 + 1] += lazy[pos];
        lazy[pos] = 0;
    }
    LL mid = (curLeft + curRight) / 2;
    if(low <= mid) update(curLeft, mid, low, high, val, pos * 2);
    if(high > mid) update(mid + 1, curRight, low, high, val, pos * 2 + 1);
}
LL query(LL curLeft, LL curRight, LL target_idx, LL pos)
{
    if(curLeft == target_idx and curRight == curLeft) return lazy[pos];
    if(lazy[pos] && curLeft != curRight) {
        lazy[pos * 2] += lazy[pos];
        lazy[pos * 2 + 1] += lazy[pos];
        lazy[pos] = 0;
    }
    LL mid = (curLeft + curRight) / 2;
    if(target_idx <= mid) return query(curLeft, mid, target_idx, pos * 2);
    else return query(mid + 1, curRight, target_idx, pos * 2 + 1);
}


// BIT
void add(b, idx, x)
    while(idx <= N)
        b[idx] += x
        idx += idx & -idx
def range_add(l,r,x): // Add v to A[a...b]
    add(B1, l, x)
    add(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r)
def sum(b, idx):
    total = 0
    while idx > 0:
        total += b[idx]
        idx -= idx & -idx
    return total
def prefix_sum(idx):
    return sum(B1, idx)*idx -  sum(B2, idx)
def range_sum(l, r): // Return sum A[1...b]
    return prefix_sum(r) - prefix_sum(l-1)

LL read(LL idx) {
  LL sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
void update(LL idx, LL val) {
  while (idx <= MaxIdx) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

// MO algorithm
struct node { LL l, r, idx; };
bool cmp(const node &x, const node &y) { 
  return x.r < y.r; 
}
LL curr = 0, BLOCK_SIZE, m;
vector<node> query[M];
vector<LL> mp(N, 0);
void add(LL x) {
  if(!mp[x]) curr++;
  mp[x]++;
}
void diminish(LL x) {
  mp[x]--;
  if(!mp[x]) curr--;
}
void solve() {
  int n, q; cin >> n >> q;
  vector<int> v(n), answer(q);
  for(int &i : v) cin >> i;
  BLOCK_SIZE = sqrt(n) + 1, m = 0;
  for(int i=0;i<q;i++) {
    LL x, y; cin >> x >> y; x--; y--;
    query[x / BLOCK_SIZE].push_back({x, y, i});
    m = max(m, x / BLOCK_SIZE);
  }
  for(int i=0;i<=m;i++) sort(all(query[i]), cmp);
  LL mo_left = 0, mo_right = -1;
  for(int i=0;i<=m;i++) {
    for(auto cur : query[i]) {
      LL left = cur.l, right = cur.r, id = cur.idx;
      while(mo_right < right) add(v[++mo_right]);
      while(mo_right > right) diminish(v[mo_right--]);
      while(mo_left < left) diminish(v[mo_left++]);
      while(mo_left > left) add(v[--mo_left]);
      answer[id] = curr;
    }
  }
  for(int i=0;i<q;i++) cout << answer[i] << '\n';
}

// MERGE SORT TREE
vector<LL> tree[5*MAXN];
LL A[N];
void build_tree(LL now , LL curLeft, LL curRight) {
     if(curLeft == curRight) {
        tree[now].push_back(A[curLeft]);
        return;
     }
     LL mid = (curLeft + curRight) / 2;
     build_tree(2 * now, curLeft, mid);
     build_tree(2 * now + 1, mid + 1 , curRight);
     tree[now] = merge(tree[2 * now] , tree[2 * now + 1]);
}
LL query(LL now, LL curLeft, LL curRight, LL l, LL r, LL k) {
    if(curRight < l || curLeft > r) return 0;
    if(curLeft >= l && curRight <= r) return lower_bound(tree[now].begin(), tree[now].end(), k) - tree[now].begin();
    LL mid = (curLeft + curRight) / 2;
    return query(2 * now, curLeft, mid, l, r, k) + query(2 * now + 1, mid + 1, curRight, l, r, k);
}

// LCA
LL n, l, timer;
vector<vector<LL>> adj;
vector<LL> tin, tout;
vector<vector<LL>> up;
void dfs(LL v, LL p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (LL i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (LL u : adj[v]) {
        if (u != p) dfs(u, v);
    }
    tout[v] = ++timer;
}
void preprocess(LL root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<LL>(l + 1));
    dfs(root, root);
}
bool is_ancestor(LL u, LL v)  {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
LL lca(LL u, LL v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (LL i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

// Longest Non-Decreasing subsequence - with duplicates
LL Longest_Increasing_or_nonDecreasing_Subsequence() {
    vector<LL> a(n);
    multiset<LL> S;
    for(LL x : a) {
        S.insert(x);
        auto it = S.upper_bound(x);
        if (it != S.end()) S.erase(it);
    }
    return S.size();

    // another one
    vector<LL> v(n, INF);
    for(LL i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if (it != v.end()) *it = a[i];
        else v.push_back(a[i]);
    }
    return v.size();
}

// multiply a big number with a 64 bit number
string mul(string bigNum, LL num) {
    LL carry = 0; string calc = "";
    for(auto ch : bigNum) {
        carry = ((ch - '0') * num + carry);
        calc += char(carry % 10 + '0');
        carry /= 10;
    }
    while(carry){
        calc += char(carry % 10 + '0');
        carry /= 10;
    }
    return calc;
}

// sieve to find prime numbers
bool is_prime[N];
vector<LL> prime;
void seive(LL n = 1e4) {
  memset(is_prime, true, sizeof(is_prime));
  for(LL i=2;i<=n;i++) {
    if(is_prime[i]) {
      for(LL j=i*i;j<=n;j+=i) is_prime[j] = false;
      prime.push_back(i);
    }
  }
}

// nCr
ull combination[50][50], fact[30];
ull nCr(ll n, ll r) {
    if(!r or r == n) return 1;
    if(r == 1) return n;
    if(combination[n][r] != -1) return combination[n][r];
    return combination[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
}

// factorial
void factorial(ll n = 20) {
    fact[0] = 1;
    rep(i, 1, n) fact[i] = fact[i - 1] * i;
}

// STRONGLY CONNECTED COMPONENT - KORASAJU ALGORITHM
vii adj[MAXN], rev_adj[MAXN], components[MAXN];
vii visited(MAXN), toposorted;
ll cnt = 0;

void dfs(ll now)
{
    visited[now] = 1;
    for(auto next : adj[now]) {
        if(!visited[next]) dfs(next);
    }
    toposorted.pb(now);
}
void dfs2(ll now)
{
    visited[now] = 1;
    components[cnt].pb(now);
    for(auto next : rev_adj[now]) {
        if(!visited[next]) dfs(next);
    }
}
void strongly_connected_component(ll n, ll m)
{
    visited.assign(n + 1, 0);
    for(ll i=0;i<m;i++) {
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        rev_adj[b].pb(a);
    }
    for(ll i=1;i<=n;i++) {
        if(!visited[i]) dfs(i);
    }
    reverse(all(toposorted));
    visited.assign(n + 1, 0);
    for(auto now : toposorted) {
        if(!visited[now]) {
            dfs2(now); cnt++;
        }
    }
}

// BRIDGES OF A GRAPH
ll timer = 0;
vii adj[MAXN];
ll visited[MAXN], in[MAXN], low[MAXN];
vpi bridges;

void FINDING_BRIDGES(ll now, ll par) {
    visited[now] = 1;
    in[now] = low[now] = timer++;
    for(auto next : adj[now]) {
        if(next == par) continue;
        if(visited[next]) low[now] = min(low[now], in[next]);
        else {
            critical_links(next, now);
            if(low[next] > in[now]) bridges.pb({min(now, next), max(now, next)});
            low[now] = min(low[now], low[next]);
        }
    }
}
void solve()
{
    ll n; cin >> n;
    rep(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(visited, 0, sizeof(visited));
    memset(in, -1, sizeof(in));
    memset(low, -1, sizeof(low));
    rep(i, 0, n-1) {
        if(!visited[i]) critical_links(i, -1);
    }
    sort(all(bridges));
    cout << bridges.size() << " critical links" << endl;
    for(auto [x, y] : bridges) cout << x << " - " << y << endl;
    rep(i, 0, n-1) adj[i].clear();
    bridges.clear();
}

// 1-D SPARSE TABLE
LL sparseTable[MAXN][(LL)log2(MAXN) + 5];
void build(LL n, vector<LL> &v)
{
    for(LL i = 0; i < n; i++) sparseTable[i][0] = v[i];
    for(LL j = 1; (1 << j) <= n; j++) {
        for(LL i = 0; (i + (1 << j) - 1) < n; i++) {
            sparseTable[i][j] = min(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}
LL query(LL L, LL R)
{
    LL j = (LL)log2(R - L + 1);
    return min(sparseTable[L][j], sparseTable[R - (1 << j) + 1][j]);
}

// 2-DIMENTIONAL SPARSE TABLE FOR A MATRIX/GRID
ll grid[MAXN][MAXN];
ll sparseTable[MAXN][MAXN][10];
void build(ll n)
{
    for(ll k=0;(1 << k)<=n;k++) {
        for(ll i=0;i+(1 << k)-1 < n;i++) {
            for(ll j=0;j+(1 << k)-1 < n;j++) {
                if(!k) sparseTable[i][j][k] = grid[i][j];
                else {
                    ll power = 1 << (k - 1);
                    sparseTable[i][j][k] = max({sparseTable[i][j][k - 1], sparseTable[i + power][j][k - 1], sparseTable[i][j + power][k - 1], sparseTable[i + power][j + power][k - 1]});
                }
            }
        }
    }
}
ll query(ll i, ll j, ll s)
{
    ll k = log2(s);
    ll power = 1 << k;
    return max({sparseTable[i][j][k], sparseTable[i + s - power][j][k], sparseTable[i][j + s - power][k], sparseTable[i + s - power][j + s - power][k]});
}
void SPARSE_TABLE()
{
    ll n, q; cin >> n >> q;
    rep(i, 0, n-1) {
        rep(j, 0, n-1) cin >> grid[i][j];
    }
    build(n);
    while(q--) {
        ll R, C, S; cin >> R >> C >> S;
        R--; C--;
        cout << query(R, C, S) << endl;
    }
}

// KRUSKAL'S SPANNING TREE (MST)
struct info {
  int u, v, w;
};
int parent[N], sz[N];
void initialize(int n) {
  for(int i=0;i<=n;i++) {
    parent[i] = i;
    sz[i] = 1;
  }
}
int root(int x) {
  if(parent[x] == x) return x;
  return parent[x] = root(parent[x]);
}
void merge(int x, int y) {
  int p = root(x);
  int q = root(y);
  if(sz[p] > sz[q]) {
    parent[p] = parent[q];
    sz[p] += sz[q];
    sz[q] = 0;
  }
  else {
    parent[q] = parent[p];
    sz[q] += sz[p];
    sz[p] = 0;
  }
}
// v should be already sorted according to weight
LL kruskal(int n, vector<info> &v) {
  initialize(n);
  LL cost = 0;
  for(auto cur : v) {
    if(root(cur.u) != root(cur.v)) {
      cost += cur.w;
      merge(cur.u, cur.v);
    }    
  }
  return cost;
}

// PRIM'S SPANNING TREE (MST)
bool marked[N];
vector<PII> adj[N]; // adj[from] -> {weight, to}

int prim(int n, int src) {
  for(int i=1;i<=n;i++) marked[i] = false;
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  int cost = 0;
  pq.push({0, src});
  while(!pq.empty()) {
    PII cur = pq.top(); pq.pop();
    if(marked[cur.second]) continue;
    cost += cur.first;
    marked[cur.second] = true;
    cc++;
    for(auto next : adj[cur.second]) {
      if(!marked[next.second]) pq.push(next);
    }
  }
  return cost;
}

// SUM OF ALL DIVISORS FROM 1 TO N IN TIME O(SQRT(N)) AND MEMORY O(1)
LL sum_in_range(LL n) {
  return n * (n + 1) / 2;
}
LL sum_all_divisors(LL n) {
  LL ans = 0;
  for(LL i=1;i*i<=n;i++) {
    LL hello = i * (n / i - i + 1); 
    LL world = sum_in_range(n / i) - sum_in_range(i); 
    ans += hello + world;
  }
  return ans;
}

// DIJKSTRA ALGORITHM FOR SSSP
struct node {
  int to;
  LL weight;

  bool operator<(const node &a) const {
    return weight > a.weight;
  }
};
vector<node> adj[N];

void dijkstra(int src, vector<LL> &dist, vector<int> &parent) {
  parent.assign(n + 1, -1);
  priority_queue<node> pq;
  pq.push({src, 0});
  dist[src] = 0;
  parent[src] = -1;
  while(!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    for(auto next : adj[cur.to]) {
      if(dist[next.to] > dist[cur.to] + next.weight) {
        dist[next.to] = dist[cur.to] + next.weight;
        pq.push({next.to, dist[next.to]});
        parent[next.to] = cur.to;
      }
    }
  }
}

// K-th SHORTEST PATH
void K_shortest(int n,int m){
    int st,des,k,u,v;
    LL w;
    scanf("%d%d%d", &st,&des,&k);
    st--,des--;
    vector <vector<pii > > edges(n);
    for(int i=0;i<m;i++){
        scanf("%d%d%lld", &u,&v,&w);
        u--,v--;
        edges[u].push_back({w,v});
    }
    vector < vector <LL> > dis(n,vector <LL> (k+1,1e8));
    vector <int> vis(n); 
    priority_queue <pii ,vector <pii >, greater< pii > > q;

    q.emplace(0LL,st);
    while(!q.empty()){
        v = q.top().second, w = q.top().first;
        q.pop();
        if(vis[v]>=k) continue;
        // for the varient, check if this path is greater than previous, if not, continue
        //if(vis[v]>0 && w == dis[v][vis[v]-1]) continue; 
        dis[v][vis[v]] = w; 
        vis[v]++;
        for(auto nd:edges[v]){
            q.emplace(w+nd.first,nd.second);
        }
    }
    LL ans = dis[des][k-1];
    if(ans==1e8) ans = -1;
    printf("%lld\n", ans);
}

// LCA RELATED
using vec = vector <int>;
using mat = vector <vector <int>>;
namespace ta {
    int time;
    void dfs(int u, int p, vec &par, vec &lvl, Tree &T) {
        for(int e: T[u]) {
            int v = T(e).to(u);
            if(v == p) continue;
            par[v] = u, lvl[v] = lvl[u] + 1;
            dfs(v, u, par, lvl, T);
        }
    }

    mat ancestorTable(vec &par) {
        int n = par.size(), sz = __lg(n) + 1;
        mat anc(sz, par);

        for(int k = 1; k < sz; k++) {
            for(int i = 0; i < n; i++) {
                anc[k][i] = anc[k - 1][anc[k - 1][i]];
            }
        }
        return anc;
    }

    int getAncestor(int u, int ht, mat &anc) {
        int sz = anc.size();

        for (int k = 0; k < sz; k++) {
            if (ht >> k & 1) u = anc[u][k];
        }
        return u;
    }

    bool isAncestor(int u, int par, vec &st, vec &en) {
        return st[par] <= st[u] and en[par] >= en[u];
    }
    int subtreeSize(int u, vec &st, vec &en) {
        return en[u] - st[u] + 1 >> 1;
    }

    int lca(int u, int v, vec &lvl, mat &anc) {
        if (lvl[u] > lvl[v]) swap(u, v);

        for (int k = anc.size() - 1; ~k; k--) {
            if (lvl[u] + (1 << k) <= lvl[v]) v = anc[k][v];
        }
        if (u == v) return u;

        for (int k = anc.size() - 1; ~k; k--) {
            if (anc[k][u] != anc[k][v]) u = anc[k][u], v = anc[k][v];
        }
        return anc[0][u];
    }

    int dis(int u, int v, vec &lvl, mat &anc) {
        int g = lca(u, v, lvl, anc);
        return lvl[u] + lvl[v] - 2 * lvl[g];
    }
}

// MAXIMUM SUBARRAY SUM
array<LL, 3> maxSubArraySum(std::vector<LL> &v, LL n) {
  LL max_so_far = -INF, max_ending_here = 0, start = 0, end = 0, s = 0;
  for(int i = 0; i < n; i++) {
    max_ending_here += v[i];
    if(max_so_far < max_ending_here) {
      max_so_far = max_ending_here;
      start = s;
      end = i;
    }
    if(max_ending_here < 0) {
      max_ending_here = 0;
      s = i + 1;
    }
  }
  return {max_so_far, start, end};
}

LL fact[N], inv[N], fact_inv[N];
void COMBINATORICS() {
  inv[0] = inv[1] = 1;
  for(LL i = 2; i < N; i++) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
  
  fact_inv[0] = fact[0] = 1;
  for(LL i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    fact_inv[i] = (fact_inv[i - 1] * inv[i]) % MOD;
  }
  auto nCr = [](LL n, LL r) {
    return (fact[n] * fact_inv[r]) % MOD * fact_inv[n - r] % MOD;
  };
}

// KMP string searching algorithm
// returns all occurances of pattern in text
vector<int> prefix_function(string &s) {
  int n = s.size();
  vector<int> pi(n);
  for(int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while(j > 0 and s[i] != s[j]) j = pi[j - 1];
    if(s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
vector<int> KMP(string &text, string &pattern) {
  string full = pattern + "#" + text;
  int n = pattern.size();
  auto pi = prefix_function(full);
  vector<int> occur;
  for(int i = n + 1; i < full.size(); i++) {
    if(pi[i] == n) occur.push_back(i - 2 * n); 
  }
  return occur;
}

// 2D HASHING 
// TIME COMPLEXITY -> O(N * N)
int n, m; // TEXT GRID
int x, y; // PATTERN GRID
unsigned long long P = 641, Q = 941; // BASES
unsigned long long baseP[N], baseQ[N], text_hsh[N][N], pattern_hsh[N][N];
void pre() {
  baseP[0] = baseQ[0] = 1;
  for(int i = 1; i < N; i++) baseP[i] = baseP[i - 1] * P;
  for(int i = 1; i < N; i++) baseQ[i] = baseQ[i - 1] * Q;
}
void generate_hash(unsigned long long arr[][N], int n, int m) {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      char c; cin >> c;
      arr[i][j] = arr[i - 1][j] * P + arr[i][j - 1] * Q - arr[i - 1][j - 1] * P * Q + (c - 'a'); 
    }
  }
}
unsigned long long get_hash(int x1, int y1, int x2, int y2) {
  return text_hsh[x2][y2] - text_hsh[x1 - 1][y2] * baseP[x2 - x1 + 1] - text_hsh[x2][y1 - 1] * baseQ[y2 - y1 + 1] + text_hsh[x1 - 1][y1 - 1] * baseP[x2 - x1 + 1] * baseQ[y2 - y1 + 1];
}
int search(int n, int m, int x, int y) {
  int ans = 0;
  for(int x1 = 1, x2 = x; x2 <= n; x1++, x2++) {
    for(int y1 = 1, y2 = y; y2 <= m; y1++, y2++) {
      ans += get_hash(x1, y1, x2, y2) == pattern_hsh[x][y];
    }
  }
  return ans;
}
 
// TRIE DATA STRUCTURE
struct node {
  bool endmark;
  node* next[10];
  node() {
    endmark = false;
    for(int i = 0; i < 10; i++) next[i] = NULL;
  }
} *root;
void insert(string &s) {
  node* cur = root;
  for (int i = 0; i < s.size(); i++) {
    if(cur->endmark == 1) good = false; 
    int c = s[i] - '0';
    if(cur->next[c] == NULL) cur->next[c] = new node();
    cur = cur->next[c];
  }
  cur->endmark = 1;
}
// searches if the string is present in the dictionary
bool search(string &s) {
  node* cur = root;
  for(int i = 0; i < s.size(); i++) {
    int c = s[i] - 'a';
    if(cur->next[c] == NULL) return false;
    cur = cur->next[c];
  }
  return cur->endmark;
}
// searches the whole trie if there is a string which matches with a prefix of another string
bool isPrefix(node* cur) {
  for(int i = 0; i < 10; i++) {
    if(cur->next[i] != NULL) {
      if(cur->endmark) return 1;
      if(isPrefix(cur->next[i])) return 1;
    }
  }
  return 0;
}
// delete trie or get RTE
void del(node* cur) {
  for(int i = 0; i < 10; i++) {
    if(cur->next[i]) del(cur->next[i]);
  }
  delete(cur);
}
void TRIE() {
  root = new node();
  // do work here
  del(root);
}

// HASHING
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
