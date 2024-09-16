#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, mx, mn;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    mx = mn = v[0];
    for(int i=1;i<n;i++) {
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    cout << mx - mn + 1 - n << endl;
    return 0;
}



