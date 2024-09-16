#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, k, x;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> k >> x;
        cout << 9 * (k - 1) + x << endl;
    }
    return 0;
}


