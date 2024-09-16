#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        if(n % 2 == 1){
            n = (n - 3) / 2;
            cout << '7';
        }
        else n /= 2;
        for(int j=1;j<=n;j++) cout << '1';
        cout << endl;
    }
    return 0;
}



