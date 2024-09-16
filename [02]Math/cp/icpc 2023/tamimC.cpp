#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define getbit(n, i) (((n) & (1LL << (i))) != 0)
#define setbit0(n, i) ((n) & (~(1LL << (i))))
#define setbit1(n, i) ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
#define lastone(n) ((n) & (-(n)))
char gap = 32;
#define int long long
#define ll long long
#define lll __int128_t
#define pb push_back
#define endl '\n'
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
const int N = 1005;
int rowPref[N];
int colPref[N][N];
string grid[N];
int n,k;

int get(int P){
    if (P < 0) return 0;
    int r = P / (n * k);
    int c = P % (n * k);

    int rp = (r / k), cp = (c / k);
    int ans = 0;
    // cout << " r = " << r << " rp = " << rp << endl;
    if (rp > 0) ans += rowPref[rp-1] * k * k;
    ans += (r - rp * k) * colPref[rp][n-1] * k;

    //cout << ans << endl;

    if (cp > 0) ans += colPref[rp][cp-1] * k;
    // cout << " * " << ans << endl;
    ans += (c - cp * k + 1) * (grid[rp][cp] - '0');
    // cout << c << " " << cp * k << endl;
    return ans;
}
void solve() {


    cin>>n>>k;

    for(int i=0;i<n;i++) cin>>grid[i];


    for(int i=0;i<n;i++){
        colPref[i][0] = grid[i][0] - '0';
        for(int j=1;j<n;j++){
            colPref[i][j] = colPref[i][j-1] + (grid[i][j] - '0');
        }
        rowPref[i] = colPref[i][n-1] + (i>0?rowPref[i-1]:0);
        // cout << i << " ->  " << rowPref[i] << endl;
    }

    // for (int i=0; i<n*k; i++) {
    //     for (int j=0; j<n*k; j++) {
    //         cout << get(i * n * k + j) - get(i * n * k + j -1 ) << " ";
    //     }
    //     cout << endl;
    // }

    int q;
    cin>>q;
    while(q--){
        int L,R;
        cin >> L >> R;
        cout << get(R) - get(L-1) << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for (int cs=1; cs <= t; cs++) {
        cout<<"Case "<<cs<<":"<<endl;
        solve();
    }
    return 0;
}

/*
2
1 1
0
1
0 0
2 2
01
10
5
0 4
3 11
6 9
4 5
0 15
*/
