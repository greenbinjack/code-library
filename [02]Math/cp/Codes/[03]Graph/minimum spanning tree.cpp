// KRUSKALS SPANNING TREE (MST)
struct info {
  int u, v, w;
};
-----> DSU code ... 
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
DIJKSTRA code ...
 start from a node, and push nodes which are not marked
 popped edges weight are taken 