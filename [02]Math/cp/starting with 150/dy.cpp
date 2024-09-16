#include<bits/stdc++.h>
using namespace std;

int calc(int y2, int y1, int divideBy)
{
    return y2 / divideBy - (y1 - 1) / divideBy;
}

int main()
{
    int tc, d1, y1, d2, y2, ans;
    string m1, m2;
    char temp;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> m1 >> d1 >> temp >> y1 >> m2 >> d2 >> temp >> y2;
        if(m1 != "January" && m1 != "February") y1++;
        if (m2 == "January" || (m2 == "February" and d2 < 29)) y2--;
        ans = calc(y2, y1, 4) + calc(y2, y1, 400) - calc(y2, y1, 100);
        cout << "Case "<< i << ": " << ans << endl;
    }
    return 0;
}

