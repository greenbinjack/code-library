#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        if(n <= 14) cout << "NO" << endl;
        else if(n % 14 >= 1 && n % 14 <= 6) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}



