#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n, ans = 0;
    cin >> n;
    for(int i=1;i<=n;i++) ans += (1.0 / i);
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}



