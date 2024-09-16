#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, temp = "";
    cin >> s;
    for(int i=0;i<s.size();i+=2) temp += s[i];
    sort(temp.begin(), temp.end());
    for(int i=0;i+1<temp.size();i++) cout << temp[i] << '+';
    cout << temp[temp.size() - 1] << endl;
    return 0;
}

