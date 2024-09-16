#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, h, m;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> h >> m;
        cout << (60 - m) + (24 - h - 1) * 60 << endl;
    }
    return 0;
}



