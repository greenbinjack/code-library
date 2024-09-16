#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, k;
    char ch;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n >> k;
        for(int i=0;i<n;i++) {
            ch = 'a' + (i % k);
            cout << ch;
        }
        cout << endl;
    }
    return 0;
}

