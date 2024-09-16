// #author: greenbinjack

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long LL;
typedef pair <int, int> PII;

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
const LL N = 2e5 + 7;
const LL MOD = 1e9 + 7;

/* --------------------------------------------------------------------------- */

void FAILED() {
  // cerr << "I am here\n";
}

void DLD_PARINA(int __) {
  string s; cin >> s;
  int n = s.size();
  vector<int> d1(n);
  // d[i] = number of palindromes taking s[i] as center
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
    d1[i] = k--;
    if (i + k > r) l = i - k, r = i + k;
  }
  vector<int> d2(n);
  // d[i] = number of palindromes taking s[i-1] and s[i] as center
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
    d2[i] = k--;
    if (i + k > r) l = i - k - 1, r = i + k;
  }
  for(int i = 0; i < n - 1; i++) {
    cout << 2 * d1[i] - 1 << ' ' << 2 * d2[i + 1] << ' ';
  }
  cout << 2 * d1[n - 1] - 1 << '\n';
} 

int main() {
  mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
  auto begin = std::chrono::high_resolution_clock::now();
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
 
  // freopen("01-comedy.txt", "r", stdin);
  // freopen("output.txt", "w", stdin);
 
  FAILED();
  int _ = 1; // cin >> _;
  // cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for(int __ = 1; __ <= _; __++) {
    cout << fixed << setprecision(1);
    // cout << "Case " << __ << ": ";
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
