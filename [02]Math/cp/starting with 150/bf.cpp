#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, s, k, temp, left, right, ans;
    map<int, int> mp;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n >> s >> k;
        for(int j=1;j<=k;j++) {
            cin >> temp;
            mp[temp]++;
        }
        left = s, right = s;
        while(left > 0) {
            if(mp[left]) left--;
            else break;
        }
        while(right <= n) {
            if(mp[right]) right++;
            else break;
        }
        ans = INT_MAX;
        if(left > 0) ans = s - left;
        if(right <= n) ans = min(ans, right - s);
        cout << ans << endl;
        mp.clear();
    }
    return 0;
}




