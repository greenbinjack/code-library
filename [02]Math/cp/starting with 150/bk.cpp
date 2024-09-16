#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h, n, a, sum = 0;
    cin >> h >> n;
    for(int i=0;i<n;i++) {
        cin >> a;
        sum += a;
    }
    if(h - sum <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}



