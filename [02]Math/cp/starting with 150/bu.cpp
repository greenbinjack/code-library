// #author: greenbinjack
// #id    : 220041224
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, a, b) for(ll i=(ll)a;i<=(ll)b;i++)
#define per(i, a, b) for(ll i=(ll)a;i>=(ll)b;i--)
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define pb push_back
#define mkp make_pair
#define all(v) v.begin(), v.end()
#define gap ' '
#define ff first
#define ss second
#define pie 2 * acos(0.0)
#define endl '\n'

const ll INF = 2e9;
const ll  MAXN = 1005;
const double prec = 1e-14;
const ll MOD = 1e9 + 7;

bool isPrime(ll x)
{
    if(x == 1) return false;
    for(ll i=2;i*i<=x;i++) {
        if(x % i == 0) return false;
    }
    return true;
}

bool cmp(ll a, ll b)
{
    ll x = a % 10; if(!x) x = 10;
    ll y = b % 10; if(!y) y = 10;
    return x < y;
}

void solve()
{
    int arr[5], id[5] = {0, 1, 2, 3, 4}, sum, mn = INT_MAX;
    for(int i=0;i<5;i++) cin >> arr[i];
    do {
        sum = 0;
        for(int i=0;i<4;i++) sum += ((arr[id[i]] + 9) / 10) * 10;
        sum += arr[id[4]];
        if(sum < mn) mn = sum;
    } while(next_permutation(id, id + 5));
    cout << mn << endl;
}

int main()
{
    fastio;

    //freopen("test_input.txt", "r", stdin);
    //freopen("angry.out", "w", stdout);

    ll T = 1; //cin >> T;
    for(ll testCase=1;testCase<=T;testCase++) {
        //cout << fixed << setprecision(9);
        //cout << "Case " << testCase << ": ";// << endl;
        solve();
    }
    return 0;
}

/*
sample cases:

10
10 2 8 1 2 4 1 20 4 5


*/


