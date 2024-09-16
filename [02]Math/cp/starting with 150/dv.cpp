#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, prev, ans, nose_size, a;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        prev = 2, ans = 0, nose_size = 5;
        for(int j=1;j<=n;j++) {
            cin >> a;
            ans += ceil((double)(a - prev) / nose_size);
            prev = a;
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}

