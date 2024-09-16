#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp, ans = 0, cnt = 0;
    cin >> n;
    for(int i=1;i<=n;i++) {
        temp = i, cnt = 0;
        while(temp > 0) {
            temp /= 10;
            cnt++;
        }
        if(cnt % 2 == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}

