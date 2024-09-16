// #author: greenbinjack

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long LL;
typedef pair<int, int> PII;

#define ordered_set tree<LL, null_type,less<LL>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<LL, null_type,less_equal<LL>, rb_tree_tag,tree_order_statistics_node_update>
#define all(v) v.begin(), v.end()

LL SET(LL N, LL pos) { return N | (1LL << pos); }
LL RESET(LL N,LL pos) { return N & ~(1LL << pos); }
bool CHECK(LL N,LL pos) { return (N & (1LL << pos)); }
LL ASK(LL x, LL y) { cout << "? " << x << " " << y << endl; LL d; cin >> d; return d; }
void QUERY(LL x, LL y) { cout << "! " << x << " " << y << endl; }
bool VALID(LL x, LL n, LL m) { return (x >= n and x <= m); } 

const LL INF = 2e9;
const LL N = 16;
const LL MOD = 1e9 + 7;

/* --------------------------------------------------------------------------- */

struct Point{
  int x, y;
};

void FAILED() {
  // cerr << "I am here\n";
}

Point v[N];
int n, dp[(1 << N)], same_line[N][N];

int solve(int mask) {
  if(mask + 1 == (1 << n)) return 0;
  if(dp[mask] != -1) return dp[mask];
  int cnt = __builtin_popcount(mask);
  if(cnt + 1 == n or cnt + 2 == n) return dp[mask] = 1;
  int ret = INF;
  for(int i = 0; i < n; i++) {
    if(CHECK(mask, i)) continue;
    for(int j = i + 1; j < n; j++) {
      if(CHECK(mask, j)) continue;
      ret = min(ret, solve(mask | same_line[i][j]) + 1);
    }
    break;
  }
  return dp[mask] = ret;
}

void DLD_PARINA(int __) {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    v[i] = {x, y};
  }
  auto cond = [](int i, int j, int k) {
    return v[i].x * v[j].y + v[j].x * v[k].y + v[k].x * v[i].y == v[j].x * v[i].y + v[k].x * v[j].y + v[i].x * v[k].y;
  };
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int mask = 0; mask = SET(SET(mask, i), j);
      for(int k = 0; k < n; k++) {
        if(k == i or k == j) continue;
        if(cond(i, j, k)) mask = SET(mask, k);
      }
      same_line[i][j] = mask;
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0) << '\n';
}


int main() {
  mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
  auto begin = std::chrono::high_resolution_clock::now();
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
 
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdin);
 
  FAILED();
  int _ = 1; cin >> _;
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for(int __ = 1; __ <= _; __++) {
    // cout << fixed << setprecision(1);
    cout << "Case " << __ << ": ";
    DLD_PARINA(__);
  }
 
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
/*

ORDERED SET OPERATIONS:
X.order_of_key(d) -> number of elements less than d in X
*X.find_by_order(d) -> number at index d in X

*/
