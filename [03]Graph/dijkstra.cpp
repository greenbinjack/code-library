struct node {
  int to;
  LL weight;
  bool operator<(const node &a) const {
    return weight > a.weight;
  }
};
vector<node> adj[N];
void dijkstra(int src, vector<LL> &dist, vector<int> &parent) {
  vector <bool> visited(n + 1, 0);
  parent.assign(n + 1, -1);
  priority_queue<node> pq;
  pq.push({src, 0});
  dist[src] = 0;
  parent[src] = -1;
  while(!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if(visited[cur.to]) continue;
    visited[cur.to] = true;
    for(auto next : adj[cur.to]) {
      if(dist[next.to] > dist[cur.to] + next.weight) {
        dist[next.to] = dist[cur.to] + next.weight;
        pq.push({next.to, dist[next.to]});
        parent[next.to] = cur.to;
      }
    }
  }
}