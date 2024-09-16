#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    if(x > a) cout << "NO" << endl;
    else {
        a -= x;
        if(a + b < y || a + b - y + c < z) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
