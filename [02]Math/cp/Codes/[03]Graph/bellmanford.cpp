void bellmanford(int n, int m, vector<int> edge[], int dist[], int src){
  fill(dist, dist + n, INT_MAX);
  dist[src] = 0;
  int i, j, k;
  vector<int> v;
  for (i = 0; i < n; i++){
    for (j = 0; j < m; j++) {
      v = edge[j];
      if (dist[v[1]] > dist[v[0]] + v[2])
        dist[v[1]] = dist[v[0]] + v[2];
    }
  }
  for (j = 0; j < m; j++){ // For checking negative loop
    v = edge[j];
    if (dist[v[1]] > dist[v[0]] + v[2]){
      fill(dist, dist + n, INT_MIN); // Negative loop detected 
      return;
    }
  }
}
