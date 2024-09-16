#include<bits/stdc++.h>
using namespace std;

int binary_to_decimal(int n)
{
    int res = 0, base = 1, rem;
    while(n) {
        rem = n % 10;
        n /= 10;
        res += rem * base;
        base *= 2;
    }
    return res;
}
int main()
{
    int tc, a1, a2, b1, b2, c1, c2, d1, d2;
    char dot;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> a1 >> dot >> b1 >> dot >> c1 >> dot >> d1;
        cin >> a2 >> dot >> b2 >> dot >> c2 >> dot >> d2;
        a2 = binary_to_decimal(a2);
        b2 = binary_to_decimal(b2);
        c2 = binary_to_decimal(c2);
        d2 = binary_to_decimal(d2);
        cout << "Case " << i << ": ";
        if(a1 == a2 && b1 == b2 && c1 == c2 && d1 == d2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}




