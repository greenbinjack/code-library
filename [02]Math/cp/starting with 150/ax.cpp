#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, sum = 0, a, b, ans = 0;
    vector<long long> arr;
    cin >> n >> m;
    for(long long i=0;i<n;i++) {
        cin >> a >> b;
        arr.push_back(a - b);
        sum += a;
    }
    if(sum <= m) cout << 0 << endl;
    else{
        sort(arr.rbegin(), arr.rend());
        for(long long i=0;i<n;i++) {
            sum -= arr[i];
            ans++;
            if(sum <= m) break;
        }
        if(sum <= m) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}

