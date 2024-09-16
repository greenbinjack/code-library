#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, m;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n >> m;
        cout << "Case " << i << ": " << (long long)n * m / 2 << endl;
    }
    return 0;
}

