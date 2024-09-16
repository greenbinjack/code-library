#include<bits/stdc++.h>
using namespace std;

int pairs(int x)
{
    return x * (x - 1) / 2;
}

int main()
{
    int n, ans = 0;
    string s;
    cin >> n;
    vector<int> firstCnt(26, 0);
    for(int i=0;i<n;i++) {
        cin >> s;
        firstCnt[s[0] - 'a']++;
    }
    for(int i=0;i<26;i++) ans += pairs((firstCnt[i] + 1) / 2) + pairs(firstCnt[i] / 2);
    cout << ans << endl;
    return 0;
}




