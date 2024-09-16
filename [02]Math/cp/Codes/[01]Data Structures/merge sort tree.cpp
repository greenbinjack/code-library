vector<LL> Tree[4 * N];
LL arr[N];
vector<LL> merge(vector<LL> v1, vector<LL> v2) {
  LL i = 0, j = 0;
  vector<LL> ret;
  while(i < v1.size() and j < v2.size()) {
    ret.push_back((v1[i] < v2[j]) ? v1[i++] : v2[j++]);
  }
  while(j < v2.size()) ret.push_back(v2[j++]);
  while(i < v1.size()) ret.push_back(v1[i++]);
  return ret;
}
void Build(LL node, LL bg, LL ed) {
  if (bg == ed) {
    Tree[node].push_back(arr[bg]);
    return;
  }
  LL leftNode = 2 * node, rightNode = 2 * node + 1;
  LL mid = (bg + ed) / 2;
  Build(leftNode, bg, mid);
  Build(rightNode, mid + 1, ed);
  Tree[node] = merge(Tree[leftNode], Tree[rightNode]);
}
LL query(LL node, LL bg, LL ed, LL l, LL r, LL k) {
  if (ed < l || bg > r) return 0;
  if (l <= bg && ed <= r) return upper_bound(Tree[node].begin(), Tree[node].end(), k) - Tree[node].begin();
  LL leftNode = 2 * node, rightNode = 2 * node + 1;
  LL mid = (bg + ed) / 2;
  return query(leftNode, bg, mid, l, r, k) + query(rightNode, mid + 1, ed, l, r, k);
}