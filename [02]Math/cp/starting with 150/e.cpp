#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 0, ans = 0;
    string s;
    cin >> n >> s;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '8') cnt++;
    }
    for(int i=1;i<=cnt;i++) {
        if(((n - i) / 10) >= i) ans = i;
    }
    cout << ans << endl;
    return 0;
}

