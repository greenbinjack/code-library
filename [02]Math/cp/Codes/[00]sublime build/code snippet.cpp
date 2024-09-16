// #author: greenbinjack
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define all(v) v.begin(), v.end()

LL SET(LL N, LL pos) { return N | (1LL << pos); }
LL RESET(LL N,LL pos) { return N & ~(1LL << pos); }
bool CHECK(LL N,LL pos) { return (N & (1LL << pos)); }
LL ASK(LL x, LL y) { cout << "? " << x << " " << y << endl; LL d; cin >> d; return d; }
void QUERY(LL x, LL y) { cout << "! " << x << " " << y << endl; }
bool VALID(LL x, LL n, LL m) { return (x >= n and x <= m); } 

const LL INF = 2e9;
const LL N = 1005;
const LL MOD = 1e9 + 7;
/* --------------------------------------------------------------------------- */
void FAILED() {
  // cerr << "I am here\n";
}
void DLD_PARINA(int __) {
  
} 
int main() {
  mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
  auto begin = std::chrono::high_resolution_clock::now();
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  // freopen("01-comedy.txt", "r", stdin);
  // freopen("output.txt", "w", stdin);
  FAILED();
  int _ = 1; cin >> _;
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for(int __ = 1; __ <= _; __++) {
    // cout << fixed << setprecision(1);
    // cout << "Case " << __ << ":\n";
    DLD_PARINA(__);
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
