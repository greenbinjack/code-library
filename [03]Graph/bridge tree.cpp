#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

using LL = long long;

const int N = 2E5 + 69;

struct Edge {
  int u, v;
  Edge(int _u = 0, int _v = 0) : u(_u), v(_v) {}
  int to(int node){ return u ^ v ^ node; }
};
struct Graph {
  int n;
  vector <vector<int>> adj;
  vector <Edge> edges;
  Graph(int _n = 0) : n(_n), adj(_n) {}
  void addEdge(int u, int v, bool dir = 1) {
    adj[u].push_back(edges.size());
    if(dir) adj[v].push_back(edges.size());
    edges.emplace_back(u, v);
  }
  int addNode() {
    adj.emplace_back();
    return n++;
  }
  Edge &operator()(int idx) { return edges[idx]; }
  vector<int> &operator[](int u) { return adj[u]; }
};
namespace BT {
  vector <vector <int>> comps;
  vector <int> depth, low, id;
  stack <int> st;
  vector <Edge> bridges;
  Graph tree;
  void dfs(int u, Graph &G, int ed = -1, int d = 0) {
    low[u] = depth[u] = d;
    st.push(u);
    for (int e : G[u]) {
      if(e == ed) continue;
      int v = G(e).to(u);
      if (depth[v] == -1) dfs(v, G, e, d + 1); 
      low[u] = min(low[u], low[v]);
      
      if(low[v] <= depth[u]) continue;
      bridges.emplace_back(u, v);
      comps.emplace_back();
      do {
          comps.back().push_back(st.top()), st.pop();
      } while(comps.back().back() != v);
    }
    if (ed == -1) {
      comps.emplace_back();
      while (!st.empty()) comps.back().push_back(st.top()), st.pop();
    }
  }
  Graph &createTree() {
    for (auto &comp : comps) {
      int idx = tree.addNode();
      for (auto &e : comp) id[e] = idx;
    }
    for (auto &[l, r] : bridges) tree.addEdge(id[l], id[r]);
    return tree;
  }
  void init(Graph &G) {
    int n = G.n;
    depth.assign(n, -1), id.assign(n, -1), low.resize(n);
    for (int i = 0; i < n; i++){
      if (depth[i] == -1) dfs(i, G);
    }
  }
}
using Tree = Graph;

void search (int cur, vector <int> &dist, vector < vector <int> > &newGraph) {
    dist[cur] = 0;
    queue<int> q;
    q.push (cur);
    while (!q.empty ()) {
        int u = q.top ();
        q.pop ();
        for (int next : newGraph[u]) {
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push (next);
            }
        }
    }
}

int main() {
  cin.tie (nullptr) -> ios_base :: sync_with_stdio (false);

  int n, m; 
  cin >> n >> m;
  Graph G (n);
  vector <Edge> edges (m);
  for(auto &[u, v]: edges) {
    cin >> u >> v;
    --u, v--;
    G.addEdge(u, v);
  }
  BT :: init(G);
  Tree T = BT :: createTree();
  using BT :: comps;
  
  vector <int> v (n);
  int color = 0;
  cout << comps.size () << endl;
  for (auto i : comps) {
    for (auto c : i) v[c] = color;
    color++;
  }

  int sz = comps.size ();
  vector < vector <int> > newGraph (sz);
  map <pair <int, int>, int> mp;
  for (int i = 0; i < m; i++) {
    int x = v[edges[i].u], y = v[edges[i].v];
    if (x > y) swap (x, y);
    if (mp.count ({x, y}) or x == y) continue;
    newGraph[x].push_back (y);
    newGraph[y].push_back (x);
  }
  
  for (int i = 0; i < n; i++) cout << v[i] << " \n"[i == n - 1];
  
  vector <int> dist (sz, -1);
  search (0, dist, newGraph);
  int pos = max_element (all (dist)) - dist.begin ();
  cout << pos << endl;
  dist.assign (sz, -1);
  search (pos, dist, newGraph);
  int pos2 = max_element (all (dist)) - dist.begin ();
  cout << pos2 << endl;
  cout << *max_element (all (dist)) << endl;
  
  int ans1 = 1, ans2 = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] == pos) ans1 = i + 1;
    else if (v[i] == pos2) ans2 = i + 1;
  }
  
  cout << ans1 << ' ' << ans2 << '\n';
  
  return 0;
}