#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, cnt;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        cnt = 0;
        while(n) {
            if(n % 2 == 1) cnt++;
            n /= 2;
        }
        cout << "Case " << i << ": ";
        if(cnt % 2 == 1) cout << "odd" << endl;
        else cout << "even" << endl;
    }
    return 0;
}

/*
sample cases:

10
10 2 8 1 2 4 1 20 4 5


*/


