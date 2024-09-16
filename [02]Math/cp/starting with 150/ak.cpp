#include<bits/stdc++.h>
using namespace std;

int calc(string op)
{
    string genome = "ACTG";
    int ans = 0, temp;
    for(int i=0;i<4;i++) {
        temp = genome[i] - op[i];
        if(temp < 0) temp += 26;
        ans += min(temp, 26 - temp);
    }
    return ans;
}

int main()
{
    int n, mn = 20000;
    string s;
    cin >> n >> s;
    for(int i=0;i<n-3;i++) mn = min(mn, calc(s.substr(i, 4)));
    cout << mn << endl;

    return 0;
}

