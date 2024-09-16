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