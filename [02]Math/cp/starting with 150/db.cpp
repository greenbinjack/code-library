#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, sum, amount;
    string s;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        sum = 0;
        cout << "Case " << i << ": " << endl;
        for(int j=1;j<=n;j++) {
            cin >> s;
            if(s == "donate") {
                cin >> amount;
                sum += amount;
            }
            else cout << sum << endl;
        }
    }
    return 0;
}

