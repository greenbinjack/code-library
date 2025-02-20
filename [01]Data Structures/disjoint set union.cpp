struct DSU{
  vector <int> par,size;
  DSU(int n) : par(n), size(n) {
    fill(size.begin(), size.end(), 1);
    iota(par.begin(), par.end(), 0);
  }
  int Anc(int node){
    if(par[node] == node) return node;
    return par[node] = Anc(par[node]); 
  }
  bool Same(int x, int y){
    return Anc(x) == Anc(y);
  }
  void Union(int x, int y){
    x = Anc(x), y = Anc(y);
    if(x == y) return;
    if(size[x] < size[y]) swap(x, y);
    size[x] += size[y], par[y] = x;
  }
  int Size(int node){
    return size[Anc(node)];
  }
};
struct Rollback_DSU {
  int n;
  vector <int> par, sz;
  vector <pair <int, int>> op;
  Rollback_DSU(int n) : par(n), sz(n, 1) {
    iota(par.begin(), par.end(), 0);
    op.reserve(n);
  }
  int Anc(int node) {
    for(; node != par[node]; node = par[node]);
    return node;
  }
  void Unite(int x, int y) {
    if(sz[x = Anc(x)] < sz[y = Anc(y)]) swap(x, y);
    op.emplace_back(x, y);
    par[y] = x;
    sz[x] += sz[y];
  }
  void Undo(size_t t) {
    for(; op.size() > t; op.pop_back()) {
      par[op.back().second] = op.back().second;
      sz[op.back().first] -= sz[op.back().second];
    }
  }
};