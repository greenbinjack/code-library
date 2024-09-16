#include<bits/stdc++.h>
using namespace std;
int to_decimal(int n)
{
    int res = 0, base = 1, rem;
    while(n) {
        rem = n % 10;
        res += base * rem;
        base *= 2;
        n /= 10;
    }
    return res;
}
int main()
{
    int tc, a1, a2, b1, b2, c1, c2, d1, d2;
    char temp;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> a1 >> temp >> b1 >> temp >> c1 >> temp >> d1;
        cin >> a2 >> temp >> b2 >> temp >> c2 >> temp >> d2;
        a2 = to_decimal(a2);
        b2 = to_decimal(b2);
        c2 = to_decimal(c2);
        d2 = to_decimal(d2);
        if(a1==a2 && b1==b2 && c1==c2 && d1==d2) cout << "Case " << i << ": " <<  "Yes" << endl;
        else cout << "Case " << i << ": " << "No" << endl;
    }
    return 0;
}
