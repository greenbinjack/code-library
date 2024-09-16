/*
    CREATED BY :
            IUT_ORAJOKOTA
            ISLAMIC UNIVERSITY OF TECHNOLOGY
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, a, b) for(ll i=(ll)a;i<=(ll)b;i++)
#define per(i, a, b) for(ll i=(ll)a;i>=(ll)b;i--)
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define endl '\n'

const ll MAXN = 1005;

string str;
ll grid[MAXN][MAXN];
ll prefSUM[MAXN][MAXN];
ll mul[MAXN][MAXN];
ll last[MAXN];
ll n, k;

ll RUINED_MY_DAY(ll x)
{
    if(x == 0) return 0;
    ll y = x / (n * k);
    ll z = x % (n * k);
    ll yy = y / k, zz = y % k;
    ll yyy = z / k, zzz = z % k;
    return last[yy] + prefSUM[yy + 1][n] * zz + prefSUM[yy + 1][yyy] + grid[yy + 1][yyy + 1] * zzz;
}

void solve()
{
    cin >> n >> k;
    rep(i, 0, n+1) {
        mul[n+1][i] = 0;
        grid[n+1][i] = 0;
        prefSUM[n+1][i] = 0;
        mul[i][0] = 0;
        grid[i][0] = 0;
        prefSUM[i][0] = 0;
    }
    rep(i, 1, n) {
        cin >> str;
        rep(j, 1, n) {
            grid[i][j] = (str[j - 1] == '1' ? 1 : 0);
            mul[i][j] = grid[i][j] * k;
        }
    }
    rep(i, 1, n) {
        rep(j, 1, n) prefSUM[i][j] = prefSUM[i][j - 1] + mul[i][j];
    }
    last[0] = 0;
    rep(i, 1, n) last[i] += last[i - 1] + prefSUM[i][n] * k;
    ll q; cin >> q;
    while(q--) {
        ll l, r; cin >> l >> r; r++;
        cout << RUINED_MY_DAY(r) - RUINED_MY_DAY(l) << endl;
    }
}

int main()
{
    fastio;
    ll T = 1; cin >> T;
    for(ll d=1;d<=T;d++) {
        cout << "Case " << d << ": " << endl;
        solve();
    }
    return 0;
}
